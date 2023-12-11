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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
ll x,a,d,n;
ll ABC(ll t)
{
	if(t<0)return -t;
	else return t;
}
ll min(ll a,ll b)
{
	if(a>=b)return b;
	else return a;
}
void solve()
{
	cin>>x>>a>>d>>n;
	n--;
	ll len=x-a;
	ll t;
	if(d==0)t=-1;
	else t=min((len)/d,n);

	if(t>=0)
	{
		ll l=a+d*t;
		ll ans=ABC(x-l);
		if(t+1<=n)
			ans=min(ans,ABC(x-(a+d*(t+1))));
		cout<<ans<<endl;
	}
	else
		cout<<ABC(len)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}