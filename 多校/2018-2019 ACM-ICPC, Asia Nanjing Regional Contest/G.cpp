#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

long long n;

long long ksm(long long a,long long b)
{
	long long res=1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
long long mod2=ksm(2,mod-2);
long long mod6=ksm(6,mod-2);

long long get(long long x)
{
	return x*(x+1)%mod*mod2%mod;
}

long long get1(long long x)
{
	return x*(2*x%mod+1)%mod*(x+1)%mod*mod6%mod;
}
long long get2(long long x,long long y)
{
	y=x;
	if(x==0) return 0;
	long long ans=0;
	ans=ksm(2,y+6)*((1-ksm(mod2,x)+mod)%mod)%mod;
	ans=(ans-x*ksm(2,y-x+5)%mod+mod)%mod;
	ans=(ans-x*x%mod*ksm(2,y-x+3)%mod)%mod;
	ans=(ans-ksm(2,y+4)*((1-ksm(mod2,x)+mod)%mod)%mod+mod)%mod;
	return ans;
}
void solve()
{
	cin>>n;
	if(n==1)
	{
		cout<<1<<'\n';
		return;
	}
	else if(n==2)
	{
		cout<<5<<'\n';return;
	}
	long long ans=0;
	ans=(ans+(n+1)*get(n)%mod)%mod;
	ans=(ans-get1(n)+mod)%mod;
	long long tp=n/2;
	long long res=0;
	res=(res+tp*(2+3*n%mod+n*n%mod)%mod)%mod;
	res=(res-(4*n%mod+6)%mod*get(tp)%mod+mod)%mod;
	res=(res+4%mod*get1(tp)%mod)%mod;
	ans=(ans+res*mod2%mod+mod)%mod;
	long long x=(n-2);
	ans=(ans+get2(x/2,x/2+(x&1)))%mod;
	if(x&1)
	{
		ans=(ans+get(x)*2%mod)%mod;
	}
	cout<<ans<<'\n';
}


int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}