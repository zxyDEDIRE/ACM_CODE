#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n, m;
vector<int>g[N];
int ptop[N], ptail[N];

int get(int x, int p[]){
	if(x != p[x]) p[x] = get(p[x], p);
	return p[x];
}

void dfs(int u, int fa){
	cout << u << " ";
	for(int v : g[u]){
		if(v != fa) dfs(v, u);
	}
}

int vis[N];
void revers(int id){

}

void solve(){
	for(int i = 1; i <= n; i ++){
		ptop[i] = ptail[i] = i;
		g[i].clear();
		vis[i] = 1;
	}

	for(int i = 1; i <= m; i ++){
		int a, b;
		cin >> a >> b;
		if(!vis[a] && !vis[b]) continue ;

		if(!vis[a] && vis[b]){
			vis[a] = 1;
			
			vis[b] = 0;
		}

		int atop = get(a, ptop);
		int atail = get(a, ptail);
		int btop = get(b, ptop);
		int btail = get(b, ptail);


		if(get(a, ptop) != get(b, ptop)){ // link
			g[atail].push_back(btop);
			g[btop].push_back(atail);
			ptop[get(a, ptop)] = get(b, ptop);
			ptail[get(a, ptail)] = get(b, ptail);
		}

		ptop[get(a, ptop)] = btail;
		ptail[get(a, ptail)] = atop;
	}

	dfs(get(1, ptop), 0);
	cout << "\n";
}

int main(){
	ios::sync_
	while(cin >> n >> m){
		solve();
	}
	return 0;
}