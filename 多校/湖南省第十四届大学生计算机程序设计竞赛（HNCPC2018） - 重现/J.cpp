#include<bits/stdc++.h>
using namespace std;
const int N=6e5+10,mod=1e9+7;
int n,m,l,r;
long long sum[N];
long long b[N];
void solve()
{
	for(int i=0;i<=n;i++)
	{
		cin>>sum[i];
		if(i) sum[i]=(sum[i-1]+sum[i])%mod;
	}
	long long ans=0;
	for(int i=0;i<=m;i++)
	{
		cin>>b[i];//i+j>=l i+j<=r
		int ll=l-i-1,rr=min(r-i,n);
		if(ll>=rr) continue;
		if(ll<0) ans=(ans+sum[rr]*b[i]%mod)%mod;
		else ans=(ans+(((sum[rr]-sum[ll])%mod+mod)%mod)*b[i]%mod)%mod; 
	}
	cout<<ans<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m>>l>>r)
		solve();

	return 0;
}