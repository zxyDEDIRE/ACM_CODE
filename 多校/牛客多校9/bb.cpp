/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int maxn=8000+11;
const int mod=998244353;
int dp[maxn][maxn];
int inv[maxn];
int p[maxn];
int n;
int fp(int b,int p){
	if(inv[b])return inv[b];
	int res=1,bb=b;
	while(p){
		if(p&1)res=(res*b)%mod;
		p>>=1;b=(b*b)%mod;
	}
	return inv[bb]=res;
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>p[i];
	dp[0][1]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			(dp[i+1][j+1]+=dp[i][j]*fp(p[j],mod-2))%=mod;
			(dp[i+1][j+p[j]+1]-=dp[i][j]*fp(p[j],mod-2))%mod;
		}
		for(int j=1;j<=n;j++)
		{
			(dp[i+1][j]+=dp[i+1][j-1])%=mod;
		}
	}
	int ans=0;
	// for(int i=1;i<=n;i++)
	// 	dp[n][i]=(dp[n][i]+dp[n][i-1])%mod;
	for(int i=0;i<n;i++)
		ans=(ans+dp[i][n]*dp[i][n]%mod)%mod;
	cout<<ans<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}