/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll n,a,b;
bool check(ll k)
{
	ll cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]<k)
		{
			ll len=k-p[i];
			cnt-=(len+a-1)/a;
		}
		else if(p[i]>=k)
		{
			ll len=p[i]-k;
			cnt+=(len)/b;
		}
		//cout<<p[i]-k<<" "<<cnt<<endl;
	}
	if(cnt>=0)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>a>>b;
	ll l,r;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(i==1)l=r=p[1];
		else l=min(l,p[i]),r=max(r,p[i]);
	}
	ll ans=l;

	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		//cout<<mid<<" "<<check(mid)<<endl;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	if(check(ans+1))cout<<ans+1<<endl;
	else cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}