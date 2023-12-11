#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;


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
long long get2(long long x)
{
	return get(x)*get(x)%mod;
}
long long n;
long long t(long long x)
{
	return ksm(2,(n-x+1)/2);
}
void solve()
{
	cin>>n;
	if(n<=2)
	{
		cout<<get1(n)<<'\n';return;
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
	for(int i=1;i<=n-2;i++)
	{
		ans=(ans+get(i)*t(i)%mod)%mod;
	}
	cout<<(n+1)*(n+2)*(n+3)*n/24<<"\n";

}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int t=1;
	cin>>t;
	while(t--)
	{
		solve();
	}

	return 0;
}
/*
7
4
5
6
7
8
9
10
*/