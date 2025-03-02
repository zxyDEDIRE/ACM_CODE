#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f; 
const int maxn=1e3+7;
int dp[maxn][maxn];
string a,b;
signed main()
{
	cin>>a>>b;
	a=" "+a;
	b=" "+b;
	int n=a.size()-1;
	int m=b.size()-1;
	memset(dp,INF,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=0;
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j])
			{
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]);
			}
			else
			{
				dp[i][j]=min(dp[i-1][j],dp[i-1][j-1]+1);
			}
		}
	}
	cout<<dp[n][m]<<endl;
	return 0;
}
/*
ABCDEABCD
XAABZ
*/
