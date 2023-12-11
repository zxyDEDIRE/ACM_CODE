#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int n,a[maxn];
long long dp[maxn][2];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	dp[1][0]=a[1];
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+a[i];
		dp[i][1]=
	}
	return 0;
}