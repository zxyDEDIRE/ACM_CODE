#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll L,n,k;
bool check(ll t)
{
	ll x=n,y=k;
	ll s=0,num=0;
	for(int i=1;i<x;i++)
	{
		if(i==1)s=0;
		ll len=p[i+1]-p[i]-1;
		num+=len/t;
	}
	if(num>k)return 0;
	else return 1;
}
void solve()
{
	cin>>L>>n>>k;
	ll l=1,r=L,ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++)
		ans=max(p[i+1]-p[i],ans);
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}