#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long a,b,x,y,x1,y2;
long long ksm(long long a,long long b)
{
	long long res=1;
	a%=mod;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
long long mod2=ksm(2,mod-2);
long long get(long long a,long long b)
{
	return a*(a+1)%mod*mod2%mod*b%mod*(b+1)%mod*mod2%mod;
}
void solve()
{
	long long ans=get(a,b);
	ans=(ans+a*b%mod*(x1-x)%mod*(y2-y)%mod)%mod;
	if(a>x&&b>y)
	{
		ans=(ans-get(a-x,b-y)+mod)%mod;
		if(a>x1)
		{
			ans=(ans+get(a-x1,b-y)+mod)%mod;
		}
		if(b>y2)
		{
			ans=(ans+get(a-x,b-y2)+mod)%mod;
		}
		if(a>x1&&b>y2)
		{
			ans=(ans-get(a-x1,b-y2)+mod)%mod;
		}
	}
	cout<<ans<<'\n';
}
/*
10 10
1 5 1 5
*/
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cout.tie(0);
	while(cin>>a>>b>>x>>x1>>y>>y2)
		solve();
	
	return 0;
}
