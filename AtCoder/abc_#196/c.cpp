/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll n;
ll f(ll x)
{
	ll cnt=0;
	while(x)
	{
		cnt++;
		x/=10;
	}
	return cnt;
}
ll fp(ll b,ll p)
{
	ll res=1;
	while(p)
	{
		if(p&1)res=(res*b);
		p>>=1;
		b=(b*b);
	}
	return res;
}
void solve()
{
	cin>>n;
	ll ans=0;
	for(ll i=1;i;i++)
	{
		ll s=f(i);
		ll t=i*fp(10,s)+i;
		//cout<<t<<" "<<i<<endl;
		if(t<=n)ans++;
		else break;
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
/*

*/