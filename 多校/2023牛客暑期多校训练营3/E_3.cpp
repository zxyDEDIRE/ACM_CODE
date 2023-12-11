#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 5;
const int maxn= 5e5+1;
const int INF = 1e9+7;

struct E {
	int v, x;
} e[MAX ];

int n, m, u, v, tot, dfc;
int ans[MAX], dfn[MAX], pos[MAX], sdm[MAX], idm[MAX], fa[MAX], mn[MAX],fth[MAX];
int h[3][MAX ];
vector<int>G[maxn];
void init()
{
	tot=0;
	dfc=0;
	// memset(e,0,sizeof(e));
	for(int i=1;i<=n;i++)
	{
		h[0][i]=h[1][i]=h[2][i]=0;
		ans[i]=0;
		dfn[i]=pos[i]=sdm[i]=idm[i]=fa[i]=mn[i]=fth[i]=0;
		G[i].clear();
	}
}
void add(int x, int u, int v) {
	e[++tot] = {v, h[x][u]};
	h[x][u] = tot;
}

void dfs(int u) {
	dfn[u] = ++dfc;
	pos[dfc] = u;
	for (int i = h[0][u]; i; i = e[i].x) {
		int v = e[i].v;
		if (!dfn[v]) {
			dfs(v);
			fth[v] = u;
		}
	}
}

int find(int x) {
	if (fa[x] == x) {
		return x;
	}
	int tmp = fa[x];
	fa[x] = find(fa[x]);
	if (dfn[sdm[mn[tmp]]] < dfn[sdm[mn[x]]]) {
		mn[x] = mn[tmp];
	}
	return fa[x];
}

void tar(int st) {
	dfs(st);
	for (int i = 1; i <= n; ++i) {
		mn[i] = fa[i] = sdm[i] = i;
	}
	for (int i = dfc; i >= 2; --i) {
		int u = pos[i], res = INF;
		for (int j = h[1][u]; j; j = e[j].x) {
			int v = e[j].v;
			if (!dfn[v]) {
				continue;
			}
			find(v);
			if (dfn[v] < dfn[u]) {
				res = std::min(res, dfn[v]);
			} else {
				res = std::min(res, dfn[sdm[mn[v]]]);
			}
		}
		sdm[u] = pos[res];
		fa[u] = fth[u];
		add(2, sdm[u], u);
		u = fth[u];
		for (int j = h[2][u]; j; j = e[j].x) {
			int v = e[j].v;
			find(v);
			if (u == sdm[mn[v]]) {
				idm[v] = u;
			} else {
				idm[v] = mn[v];
			}
		}
		h[2][u] = 0;
	}
	for (int i = 2; i <= dfc; ++i) {
		int u = pos[i];
		if (idm[u] != sdm[u]) {
			idm[u] = idm[idm[u]];
		}
	}
	for (int i = dfc; i >= 2; --i) {
		++ans[pos[i]];
		ans[idm[pos[i]]] += ans[pos[i]];
	}
	++ans[1];
}
bitset<maxn>vis;
int flag=0;
int dfs1(int x)
{
	if(flag)return 0;
	int num=1;
	for(auto y:G[x])
	{
		if(ans[y]>ans[x])continue;
		num+=dfs1(y);
	}
	if(num!=ans[x])flag=1;
	return num;
}
void solve()
{
	cin >> n >> m;
	init();
	for (int i = 1; i <= m; ++i) {
		cin >> u >> v;
		add(0, u, v);
		add(1, v, u);
		G[u].push_back(v);
	}
	tar(1);
	vis.reset();
	flag=0;
	dfs1(1);
	if(ans[1]!=n)flag=1;
	if(flag)cout<<"No\n";//<<endl;
	else cout<<"Yes\n";//<<endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
3 2
1 2
1 3
*/