#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
vector<int>v[51];
int f[51][22];
int dp[51];
int n,m;
void dfs(int x,int fa=0)
{
	f[x][0]=fa;
	for(int i=1;i<20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:v[x])
		if(y!=fa&&y!=x)
			dfs(y,x);
	for(int i=0;i<20;i++)
		dp[x]=min(dp[f[x][i]]+1,dp[x]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=2;i<=n;i++)
		dp[i]=1e9+7;
	dp[1]=0;
	dfs(1);
	cout<<dp[n]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}