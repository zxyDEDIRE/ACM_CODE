#include<bits/stdc++.h>
using namespace std;
const int N=2022;
const int mod=1e9+7;
long long dp[N][N][4];
int n,m;

void solve()
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			for(int k=0;k<4;k++)
				dp[i][j][k]=0;
	for(int i=1;i<=max(n,m);i++)
		for(int k=0;k<=3;k++)
			dp[i][0][k]=dp[0][i][k]=1;
	dp[1][1][3]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==j&&i==1)continue;
			for(int k1=0;k1<=3;k1++)
				for(int k2=0;k2<=3;k2++)
					dp[i][j][0]=(dp[i][j][0]+dp[i-1][j][k1]*dp[i][j-1][k2])%mod;
			for(int k1=1;k1<=3;k1+=2)
				for(int k2=1;k2<=3;k2++)
					dp[i][j][1]=(dp[i][j][1]+dp[i-1][j][k1]*dp[i][j-1][k2])%mod;
			for(int k1=2;k1<=3;k1++)
				for(int k2=2;k2<=3;k2++)
					dp[i][j][2]=(dp[i][j][2]+dp[i-1][j][k1]*dp[i][j-1][k2])%mod;
			dp[i][j][3]=(dp[i-1][j][3]*dp[i][j-1][3])%mod;
		}
	}
	int ans=0;
	for(int i=0;i<=3;i++)
		ans=(ans+dp[n][m][i])%mod;
	cout<<ans<<endl;
}
signed main()
{
	while(cin>>n>>m)
		solve();
	return 0;
}