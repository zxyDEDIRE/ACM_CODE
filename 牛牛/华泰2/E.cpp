#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
const int maxn=100;
int dp[maxn];
int f(int n,int l)
{
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=l;j++)
			if(i-j>=0){
				dp[i]+=dp[i-j];
				dp[i]%=mod;
			}
	return dp[n];
}
void solve()
{	
	int n,l,r;
	cin>>n>>l>>r;
	int a=f(n,l-1);
	int b=f(n,r);
	// cout<<a<<" "<<b<<endl;
	int c=(b-a)%mod;
	c=(c+mod)%mod;
	cout<<c<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}