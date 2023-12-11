#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
__int128 ksm(__int128 b,__int128 p)
{
	__int128 res=1;
	while(p){
		if(p&1)res=(res*b)%mod;
		b=(b*b)%mod;
		p>>=1;
	}
	return res;
}
__int128 A(int n)
{
	__int128 inv = ksm(25,mod-2);
	__int128 a=(ksm(26,n)-1+mod)%mod;
	a=(a*26)%mod;
	a=(a*inv)%mod;
	// cout<<"A "<<a<<endl;
	__int128 b=ksm(26,n+1);
	b=(b*n)%mod;
	// cout<<"b "<<b<<" "<<a<<" "<<b-a<<" "<<(b-a)/25<<endl;
	a=(b-a)%mod;
	a=(a+mod)%mod;

	a=(a*inv)%mod;
	a=(a*25)%mod;
	return a;
}
__int128 B(__int128 n)
{
	__int128 a=A(n);
	__int128 b=(a*26)%mod;
	return b;
}
void solve()
{
	int n;
	cin>>n;
	__int128 N=n;
	__int128 ans=0;
	ans+=A(N/2);
	ans+=B((N-1)/2);
	ans%=mod;
	int r = ans;
	cout<<r<<endl;
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