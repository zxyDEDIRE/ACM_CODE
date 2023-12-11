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
ll n,m;
ll A(ll x)
{
	ll l=2,r=x,ans=l;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if((mid+1)*(mid-1)<=x)ans=mid,l=mid;
		else r=mid;
	}
	return ans;
}
void solve()
{
	 cin>>n>>m;
	 if(n<=2||m<=1){
	 	cout<<0<<endl;
	 	return ;
	 }
	 ll l=A(n);
	 ll r=m;
	 if(r<=l)
	 {
	 	ll t=min(l,r);
	 	t--;
	 	ll ans=(1+t)*t/2;
	 	cout<<ans<<"\n";
	 }
	 else
	 {
	 	 ll t=l;
	 	 t--;
	 	 ll ans=(1+t)*t/2;
	 	 // for(ll i=l+2;i<=m+1;i++)
	 	 // 	ans+=max(0ll,n/i);

	 	 ll S=1;
	 	 while(S<=(n/(l+2)))
	 	 {
	 	 	ll T=S+1;
	 	 	ll L=max(l+2,n/T);
	 	 	ll R=min(m+1,n/S);
	 	 	if(R-L>=0)ans+=(R-L)*S;
	 	 	S=n/(n/T);
	 	 	if(S>(n/(l+2)))break;
	 	 }
	 	 ans+=n/(l+2);

	 	 
	 	 
	 	 cout<<ans<<"\n";
	 }
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
/*
3
4 8
5 10 15
6 12 18 24
7 14 21 28 35
8 16 24 32 40 48

2 1
3 2
4 3
5 4
*/