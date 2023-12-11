#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2011,mod=1e9+7;
int dp[N][N];
int n,m;
void solve()
{
	cout<<(dp[n][m]*dp[n][m])%mod<<'\n';
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	for(int i=1;i<=2000;i++)
	{
		for(int j=1;j<=2000;j++)
			dp[i][j]=(dp[i-1][j]+dp[i][j-1]+1)%mod;
	}
	while(cin>>n>>m)
	solve();
	return 0;
}