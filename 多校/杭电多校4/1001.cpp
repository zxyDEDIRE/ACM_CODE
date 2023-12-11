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
const int INF=0x3f3f3f3f;
const int maxn=500+7;
ll dp[maxn][maxn];
ll p[maxn];
ll n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			if(p[i]>0)
			{
				if(j>=1)dp[i][j]+=dp[i-1][j-1];
			}
			else if(p[i]<0)
			{
				if(j+1<=i)dp[i][j]+=dp[i-1][j+1];
			}
			else
			{
				if(j>=1)dp[i][j]+=dp[i-1][j-1];
				if(j+1<=i)dp[i][j]+=dp[i-1][j+1];
			}
		}
	}
	cout<<dp[n][0]<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}