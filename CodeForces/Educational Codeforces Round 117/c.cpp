/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll n,k;
ll f(ll x)
{
	ll ans;
	if(x<=n)
	{
		ans=(1+x)*x/2;
	}
	else if(x>n)
	{
		ans=(1+n)*n/2;
		ll s=n-(x-n);
		ll t=n-1;
		ans+=(s+t)*(t-s+1)/2;
	}
	return ans;
}

void solve()
{
	cin>>n>>k;
	ll l=0,r=n*2-1,ans=0;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		ll t=f(mid);
		if(t==k){
			cout<<mid<<endl;
			return ;
		}
		if(t<k)ans=mid,l=mid;
		else r=mid;
	}
	if((ans+2<=n)&&f(ans+1)<k)cout<<ans+2<<endl;
	else cout<<ans+1<<endl;

}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}