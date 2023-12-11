#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int N = 1e5 + 10, inf = 0x3f3f3f3f;

int a[N];
vector<int> g[N], c[N];

int f[N][110]; // 从 i 点出发到达辣度低于等于j的店的最近距离

void solve(){
	int n, m, q;
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		c[a[i]].push_back(i);
	}

	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= n; i ++){
		for(int j = 100; j >= a[i]; j --) f[i][j] = 0;
	}

	for(int i = 1; i <= 100; i ++){
		for(auto u : g[i]){
			for(auto v : g[u]){
				int min_u = inf, min_v = inf;
				for(int j = 1; j <= 100; j ++){
					min_u = min(f[u][j], min_u);
					min_v = min(f[v][j], min_v);
					f[v][j] = min({f[v][j], min_v, min_u + 1});
					f[u][j] = min({f[u][j], min_u, min_v + 1});
					min_u = min(f[u][j], min_u);
					min_v = min(f[v][j], min_v);
				}
			}

		}
	}

	for(int i = 1; i <= q; i ++){
		int p, w;
		cin >> p >> w;
		if(f[p][w] == inf) cout << "-1\n";
		else cout << f[p][w] << "\n";
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();

	return 0;
}