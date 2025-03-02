#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
const int maxn=1e6+7;
int dp[maxn][20];
int n;
signed main()
{
	cin>>n;
	for(int i=1;i<=9;i++)dp[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=9;j++)
		{
			if(j!=1)dp[i][j]+=dp[i-1][j-1],dp[i][j]%=mod;
			dp[i][j]+=dp[i-1][j],dp[i][j]%=mod;
			if(j!=9)dp[i][j]+=dp[i-1][j+1],dp[i][j]%=mod;
		}
	}
	int t=0;
	for(int i=1;i<=9;i++)
		t=(t+dp[n][i])%mod;
	cout<<t<<endl;
}
