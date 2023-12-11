#include<bits/stdc++.h>
#define int long long
using ll=long long;
using namespace std;
const int maxn=1e6;
const int mod=1e9+7; 

ll fp(ll b,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1)res=(res*b)%mod;
		p>>=1;
		b=(b*b)%mod;
	}
	return res;
}

signed main(){
	int a,b;
	cin>>a>>b;
	pow(a,b);
	cout<<fp(a,b)<<endl;
}
