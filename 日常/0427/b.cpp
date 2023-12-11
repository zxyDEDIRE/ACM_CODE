#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
const int mod=998244353;
int n,m,p,q,ans=0;;
int mp[N][N];
int dp[N][N];
signed main()
{
	cin>>n>>m>>p>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	dp[mp[1][1]][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)
				continue;
			if(mp[i][j])
			{
				for(int k=i+j-1;k>=0;k--)
				{
					dp[k][j]=dp[k-1][j]+dp[k-1][j-1];
					dp[k][j]%=mod;
				}
				dp[0][j]=0;
			}
			else
			{
				for(int k=i+j-1;k>=0;k--)
				{
					dp[k][j]+=dp[k][j-1];
					dp[k][j]%=mod;
				}
			}
		}
	}
	for(int i=q;i<n+m-p;i++)//满足1个个数为i个，i>q,且0的个数不少于p个
	{
		ans+=dp[i][m];
		ans%=mod;
	}
	cout<<ans<<endl;
	return 0;
}
