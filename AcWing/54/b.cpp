/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int a[maxn],b[maxn];
ll n,xa,ya,xb,yb;
ll f(ll x,ll y,ll xx,ll yy)
{
	return (x-xx)*(x-xx)+(y-yy)*(y-yy);
}
void solve()
{
	cin>>n>>xa>>ya>>xb>>yb;
	for(int i=1;i<=n;i++)
	{
		ll x,y;
		cin>>x>>y;
		a[i]=f(x,y,xa,ya);
		b[i]=f(x,y,xb,yb);
	}
	ll ra=0,rb=0;
	ll ans=1e18;
	for(int i=1;i<=n;i++)
	{
		ra=a[i];
		rb=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j||a[j]<=ra)continue;
			rb=max(rb,b[j]);
		}
		ans=min(ans,ra+rb);
	}
	for(int i=1;i<=n;i++)
	{
		rb=b[i];
		ra=0;
		for(int j=1;j<=n;j++)
		{
			if(i==j||b[j]<=rb)continue;
			ra=max(ra,a[j]);
		}
		ans=min(ans,ra+rb);
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}