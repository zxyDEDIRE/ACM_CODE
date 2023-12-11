/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9+7;
const int maxn=5011;
ll dp[maxn][maxn];
ll t[maxn];
ll p[maxn];
ll n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		t[x]=y;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			dp[i][0]=max(dp[i][0],dp[i-1][j]);
			if(j>0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]+p[i]+t[j]);
		}
	}
	ll ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,dp[n][i]);
	cout<<ma<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}