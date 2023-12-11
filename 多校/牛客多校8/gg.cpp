#include <bits/stdc++.h>
#define endl '\n'
#define int unsigned long long
using namespace std;
// const ll mod = 1000000007;
//const ll mod = 998244353;

const int maxn = 1e6;
int n,m,mod,x,a,b,c,ans;
map<int,int> mp;
void solve()
{
	mp.clear();
	ans=0;
	cin>>n>>m>>mod;
	cin>>x>>a>>b>>c;
	for(int i=1;i<=n;i++)
	{
		x=(a*x*x+b*x+c)%mod;
		if(mp[x])
			continue;
		else
			mp[x]=i;
	}
	for(int i=1;i<=m;i++)
	{
		x=(a*x*x+b*x+c)%mod;
		if(mp[x])
			ans=max(ans,min(m-i+1,n-mp[x]+1));
	}
	cout<<ans<<endl;
}


signed main()
{
	int __=1;

	cin>>__;
	
	while(__--)
		solve();
	return 0;
}