#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510, M = 1e5 + 10;
const ll inf = 1e18;
int n, m;
struct quer{
	int s, t, w, op, id;
	bool operator < (const quer &A)const{
		return w < A.w;
	}
}b[M];

struct node{
	int u, w;
	bool operator < (const node &A)const{
		return w < A.w;
	}
}p[N];

ll f[N][N][3], ans[M];

void update(int id){
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			for(int k = 0; k < 2; k ++){
				f[i][j][k] = min(f[i][j][k], f[i][id][k] + f[id][j][k]);
			}
		}
	}
}

int a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		cin >> a[i];
		p[i] = {i, a[i]};
	}

	sort(p + 1, p + 1 + n);

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= n; j ++){
			f[i][j][0] = f[i][j][1] = inf;
		}
		f[i][i][0] = f[i][i][1] = 0;
	}

	for(int i = 1; i <= m; i ++){
		int s, t, w, op;
		cin >> s >> t >> w >> op;
		f[s][t][op] = f[t][s][op] = min(f[s][t][op], 1LL * w);
	}

	int q;
	cin >> q;
	for(int i = 1; i <= q; i ++){
		cin >> b[i].s >> b[i].t >> b[i].w >> b[i].op;
		b[i].id = i;
	}

	sort(b + 1, b + 1 + q);

	for(int i = 1, r = 0; i <= q; i ++){
		auto [s, t, w, op, id] = b[i];
		while(r + 1 <= n && p[r + 1].w <= w){
			update(p[++ r].u);
		}
		if(a[s] > w || a[t] > w){
			ans[id] = -1;
			continue ;
		}
		ans[id] = f[s][t][op];
		if(ans[id] == inf) ans[id] == -1;
	}

	for(int i = 1; i <= q; i ++){
		cout << ans[i] << "\n";
	}
	return 0;
}