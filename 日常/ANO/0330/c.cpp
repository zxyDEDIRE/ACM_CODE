#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=998244353;
int n,m,k;
int fp(int b,int p)
{
	int qe=1;
	while(p)
	{
		if(p&1)qe=(qe*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return qe;
}
int exgcd(int a,int b,int& x,int& y)
{
	if(b==0)return x=1,y=0,a;
	int d=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return d;
}
void solve()
{
	cin>>n>>m>>k;
	if(m*k<n){
		cout<<0<<endl;
		return ;
	}
	//if(n==m){
	//	cout<<1<<endl;
	//	return ;
	//}
	int s=1,t=1;
	s=fp(n-m,k)*n%mod;
	t=fp(n,k);
	cout<<s<<" "<<t<<endl;
	int x,y;
	exgcd(t,mod,x,y);
	x=(x%mod+mod)%mod;

	int ans=s*x%mod;


	cout<<(1-ans+mod+mod)%mod<<endl;

	
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
665496236
*/