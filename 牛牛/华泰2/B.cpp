#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
#define int long long
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
void solve()
{
	int n;
	cin>>n;
	if(n==1){
		cout<<0<<endl;
		return ;
	}
	int x=(n/2);
	int y=(n+1)/2; 
	cout<<x<<" "<<y<<endl;
	x%=mod;
	y%=mod;
	// cout<<y<<endl;
	int ans=ksm(26,y);
	// cout<<ans<<endl;
	int a=25*x;a%=mod;
	ans=(ans*a)%mod;
	cout<<ans<<endl;
	// cout<<26*26*25*25<<endl;
	// cout<<33800<<" "<<33800/26<<" "<<1300/26;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
	solve();
	return 0;
}
/*
1000000000000
999999999999
*/