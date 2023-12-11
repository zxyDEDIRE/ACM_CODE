#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
int ksm(int b,int p)
{
	int res=1;
	while(p){
		if(p&1)res=(res*b)%mod;
		b=(b*b)%mod;
		p>>=1;
	}
	return res;
}
int A(int n)
{
	int inv = ksm(25,mod-2);
	int a=(ksm(26,n)-1+mod)%mod;
	a=(a*26)%mod;
	a=(a*inv)%mod;
	// cout<<"A "<<a<<endl;
	int b=ksm(26,n+1);
	b=(b*n)%mod;
	// cout<<"b "<<b<<" "<<a<<" "<<b-a<<" "<<(b-a)/25<<endl;
	a=(b-a)%mod;
	a=(a+mod)%mod;

	a=(a*inv)%mod;
	a=(a*25)%mod;
	return a;
}
int B(int n)
{
	int a=A(n);
	int b=(a*26)%mod;
	return b;
}
void solve()
{
	int n;
	cin>>n;
	int ans=0;
	ans+=A(n/2);
	ans+=B((n-1)/2);
	ans%=mod;
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
	solve();
	return 0;
}
/*
1000000000000
999999999999
*/