#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;

vector<int> g[N];

int sg[N];
int get_mex(vector<int>& mex){
	sort(mex.begin(), mex.end());
	int siz = mex.size(), Mex = 0;
	for(int i = 0; i < siz; i ++){
		if(mex[i] == Mex) Mex ++;
		else if(mex[i] > Mex) return Mex;
	}
	return Mex;
}

int p[N];
int root;
int dfs(int u){
	p[u] = root;
	vector<int> mex;
	int sum = 0;
	for(auto v : g[u]){
		if(p[v]) continue ;
		sum ++;
		mex.push_back(dfs(v));				
	}
	if(!sum) return sg[u] = 1;
	return sg[u] = get_mex(mex);
}

void solve(){
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= m; i ++){
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	memset(sg, -1, sizeof sg);

	for(int i = 1; i <= n; i ++){
		root = i;
		if(!p[i]) dfs(i);
	}

}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	solve();
	return 0;
}