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
const int mod=998244353;
const int maxn=3000;
ll dp[maxn][maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	dp[1][0]=m;
	for(int i=2;i<=n;i++)
	{
		for(int j=0;j<=min(i-1,k);j++)
		{
			dp[i][j]+=dp[i-1][j]%mod;
			dp[i][j]%=mod;
			dp[i][j+1]+=(dp[i-1][j]*(m-1))%mod;
			dp[i][j+1]%=mod;
		}
	}
	cout<<dp[n][k]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}