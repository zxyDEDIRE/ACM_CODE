#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
vector<int>v[maxn];
int dp[maxn];
int a[maxn];
int n;
int dfs(int x,int fa)
{
	if(dp[x])return dp[x];
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa)continue;
		if(a[y]<=a[x])continue;
		dfs(y,x);
		if(a[y]>a[x])
			dp[x]=max(dp[y],dp[x]);
	}
	dp[x]++;
	return dp[x];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x); 
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		ma=max(ma,dfs(i,0));
		//cout<<dfs(i,0)<<endl;
	}
	cout<<ma<<endl;
}
