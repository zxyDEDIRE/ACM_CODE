#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 10, inf = 1e9, M = (1 << 18);

int n, m, a[21], vis[21][N], dis[21][N];
double p[N];

struct node{
	int u, ti;
	bool operator < (const node& A)const{
		return ti > A.ti;
	}
};

vector<pii> g[N];
priority_queue<node> q;
void djs(int s, int id){
	for(int i = 1; i <= n; i ++) dis[id][i] = inf;
	while(!q.empty()) q.pop();

	dis[id][s] = 0;
	q.push({s, 0});
	while(!q.empty()){
		auto [u, ti] = q.top(); q.pop();
		if(vis[id][u]) continue ;
		vis[id][u] = 1;
		for(auto [v, w] : g[u]){
			if(w + dis[id][u] < dis[id][v]){
				dis[id][v] = dis[id][u] + w;
				q.push({v, dis[id][v]});
			}
		}

	}
}

double f[M][20];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	double t, r;
	cin >> t >> r;
	cin >> n >> m;
	for(int i = 1; i <= m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	int k;
	cin >> k;
	for(int i = 0, pi; i < k; i ++){
		cin >> a[i] >> pi;
		p[i] = (double)pi / 100.0;
	}
	a[k] = 1;
	a[k + 1] = n;

	for(int i = 0; i < k + 2; i ++) djs(a[i], i);
	
	if(dis[k][n] == inf){
		cout << "-1";
		return 0;
	}

	for(int i = 0; i < M; i ++){
		for(int j = 0; j < k; j ++) f[i][j] = 1e18;
	}

	// f[state][j]:从j出发，且之后只在状态state表示的自行车节点走，走到n的最小期望时间
	double ans = (double)dis[k][n] / t; // 直接走过去
	if(k == 0){
		cout << fixed << setprecision(20) << ans <<"\n";
		return 0;
	}

	for(int i = 0; i < k; i ++){
		double res1 = (double)dis[k + 1][a[i]] / r * (1.0 - p[i]); // 车是好的
		double res2 = (double)dis[k + 1][a[i]] / t * p[i]; // 车坏了
		f[1 << i][i] = res1 + res2;
		// printf("f[%d] = %lf\n", i, f[1 << i][i]);
	}

	for(int i = 1; i < (1 << k); i ++){ // 枚举上一个状态
		for(int j = 0; j < k; j ++){ // 枚举上一个状态的起点
			if(!((1 << j) & i)) continue ; // 之前的状态必须包含起点
			for(int l = 0; l < k; l ++){ // 枚举当前节点
				if((1 << l) & i) continue ;
				// printf("j = %d l = %d\n", a[j], a[l]);
				double res1 = (double)dis[k + 1][a[l]] / r * (1.0 - p[l]); // 车好

				double res2 = ((double)dis[l][a[j]] / t + f[i][j]) * p[l]; // 车坏，走到下一个的起点
				double res3 = (double)dis[k + 1][a[l]] / t * p[l];
				// printf("res1 = %lf res2 = %lf dis1 = %lf\n", res1, res2, dis[k + 1][a[l]] / r);
				f[i | (1 << l)][l] = min(f[i | (1 << l)][l], res1 + min(res2, res3));
			}
		}
	}
	for(int i = 0; i < k; i ++){
		double res = (double)dis[k][a[i]] / t;
		ans = min(ans, f[(1 << k) - 1][i] + res);
		// printf("f%d = %lf\n", i, f[(1 << k) - 1][i]);
	}
	cout << fixed << setprecision(20) << ans <<"\n";
	return 0;
}