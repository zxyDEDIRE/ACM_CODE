#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e4 + 10, M = 2025, SIZ = 2019;
ll sum[N][M], n;
vector<pair<int,int>>g[N];

ll ans;

void dfs(int old,int now,int w)
{
	for(auto [u,ww]:g[now])

	{
		if(u==old) continue;
		dfs(now,u,ww);
		for(int i=0;i<SIZ;i++)
		{
			ans+=1ll*sum[u][i]*sum[now][(SIZ-i+SIZ)%SIZ];
		}
		for(int i=0;i<SIZ;i++)
		{
			sum[now][i]+=sum[u][i];
		}
	}
	for(int i=0;i<SIZ;i++)
		sum[now][i]=0;
	for(auto [u,ww]:g[now])
	{
		if(u==old) continue;
		for(int i=0;i<SIZ;i++)
			sum[now][(i+w)%SIZ]+=sum[u][i];
	}
	if(now==1) return;
	sum[now][w]++;
	ans+=sum[now][0];
		
}
void solve(){
	for(int i = 1; i <= n; i ++){
		g[i].clear();
		for(int j = 0; j < SIZ; j ++){
			sum[i][j] = 0;
		}
	}
	for(int i = 1; i < n; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}

	ans = 0;
	dfs(0,1,0);
	cout << ans << "\n";
	return ;
}

int main(){
	 ios::sync_with_stdio(false);
	 cin.tie(0);cout.tie(0);
	while(cin >> n){
		solve();
	}
	return 0;
}