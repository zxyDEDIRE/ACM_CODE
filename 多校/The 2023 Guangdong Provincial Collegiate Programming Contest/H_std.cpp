#include <bits/stdc++.h>
#define MAXN ((int) 5e5)
#define MAXM ((int) 5e5)
using namespace std;

int n, m, OP[MAXM + 10][4];
vector<int> ans;

vector<int> e[MAXN + 10], v[MAXN + 10];
// col[i]：点 i 属于哪个强连通分量
int clk, bCnt, dfn[MAXN + 10], low[MAXN + 10], col[MAXN + 10];
bool inStk[MAXN + 10];
stack<int> stk;

// in[i]：强连通分量 i 的入度
int in[MAXN + 10];
// vis[i]：dfs 构造答案的过程中，节点 i 是否被访问过
bool vis[MAXN + 10];

// tarjan 求强连通分量
void tarjan(int sn) {
	low[sn] = dfn[sn] = ++clk;
	stk.push(sn); inStk[sn] = true;
	for (int fn : e[sn]) {
		if (!dfn[fn]) {
			tarjan(fn);
			low[sn] = min(low[sn], low[fn]);
		} else if (inStk[fn]) {
			low[sn] = min(low[sn], dfn[fn]);
		}
	}
	if (dfn[sn] == low[sn]) {
		++bCnt;
		while (stk.top() != sn) {
			col[stk.top()] = bCnt;
			inStk[stk.top()] = false;
			stk.pop();
		}
		col[stk.top()] = bCnt;
		inStk[stk.top()] = false;
		stk.pop();
	}
}

// 从节点 sn 开始 dfs，并按 dfs 序将访问过的每条边加入 vec 里
void dfs(int sn, vector<int> &vec) {
	vis[sn] = true;
	for (int i = 0; i < e[sn].size(); i++) {
		int fn = e[sn][i];
		int val = v[sn][i];
		vec.push_back(val);
		if (!vis[fn]) dfs(fn, vec);
	}
}

void solve() {
	scanf("%d%d", &n, &m);

	vector<int> one, two;
	for (int i = 1; i <= n; i++) e[i].clear(), v[i].clear();
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < 4; j++) scanf("%d", &OP[i][j]);
		if (OP[i][1] == 1 && OP[i][3] == 1) {
			// 两个数都改成 1，最差的操作
			one.push_back(i);
		} else if (OP[i][1] == 2 && OP[i][3] == 2) {
			// 两个数都改成 2，最好的操作
			two.push_back(i);
		} else if (OP[i][1] == 1) {
			// 图中加一条从 1 指向 2 的边
			e[OP[i][0]].push_back(OP[i][2]);
			v[OP[i][0]].push_back(i);
		} else {
			// 图中加一条从 1 指向 2 的边
			e[OP[i][2]].push_back(OP[i][0]);
			v[OP[i][2]].push_back(i);
		}
	}

	// 顺序输出的答案中，两个数都改成 1 的最差操作最先输出
	ans.clear();
	for (int x : one) ans.push_back(x);

	memset(dfn, 0, sizeof(int) * (n + 3));
	clk = bCnt = 0;
	for (int sn = 1; sn <= n; sn++) if (!dfn[sn]) tarjan(sn);

	memset(in, 0, sizeof(int) * (n + 3));
	for (int sn = 1; sn <= n; sn++) {
		for (int fn : e[sn]) if (col[sn] != col[fn]) in[col[fn]]++;
	}

	vector<int> vec;
	memset(vis, 0, sizeof(bool) * (n + 3));
	// 如果一个入度为 0 的强连通分量受一个 (l_i, 2, r_i, 2) 操作影响，那么需要从 l_i 或 r_i 开始 dfs
	for (int x : two) 
	{
		for (int j = 0; j < 4; j += 2)
		{
			int sn = OP[x][j];
			if (in[col[sn]] == 0 && !vis[sn]) dfs(sn, vec);
		}
	}
		
	// 剩下的入度为 0 的强连通分量，随便找一个点开始 dfs
	for (int sn = 1; sn <= n; sn++) {
		if (in[col[sn]] == 0 && !vis[sn]) dfs(sn, vec);
	}
	// dfs 序是答案的倒序
	reverse(vec.begin(), vec.end());
	ans.insert(ans.end(), vec.begin(), vec.end());

	// 顺序输出的答案中，两个数都改成 2 的最好的操作最后输出
	for (int x : two) ans.push_back(x);

	// 计算序列最终的和
	unordered_map<int, int> mp;
	for (int x : ans) {
		mp[OP[x][0]] = OP[x][1];
		mp[OP[x][2]] = OP[x][3];
	}
	int tot = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) tot += it->second;
	printf("%d\n", tot);
	for (int i = 0; i < m; i++) printf("%d%c", ans[i], "\n "[i + 1 < m]);
}

int main() {
	int tcase; scanf("%d", &tcase);
	while (tcase--) solve();
	return 0;
}