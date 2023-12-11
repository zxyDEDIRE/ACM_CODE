#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const ll mod=1e9+7;
const int maxn=1e6;
ll p[maxn];
int n,q;
ll power(int b,int p)
{
	ll r=1;
	while(p)
	{
		if(p%2)r=(r*b)%mod;
		b=(b*b)%mod;
		p>>=1;
	}
	return r;
}
int main()
{	ios
	
	cin>>n>>q;
	p[0]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		p[i]=(p[i]*p[i-1])%mod;
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<power(p[x-1],mod-2)<<" "<<p[y]<<endl;
		//cout<<p[y]*power(p[x-1],mod-2)%mod<<endl;
	}
	
	
}