/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll p[maxn];
ll n,m;
bool check(ll k)
{
	ll a=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]<=k)a+=(k-p[i])/2;
		else
		{
			a-=(p[i]-k);
		}
	}
	if(a>=0)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		p[i]=0;
	for(int i=1;i<=m;i++)
	{
		ll x;
		cin>>x;
		p[x]++;
	}
	ll l=1,r=2*m,ans=r;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(check(ans-3))cout<<ans-3<<endl;
	else if(check(ans-2))cout<<ans-2<<endl;
	else if(check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}