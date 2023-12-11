#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
ll n,m;
bool check(ll x)
{
	ll a=x-1;
	ll b=m-a;
	b=(1+b)*b/2;
	if(a+b<=n)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m;
	ll l=1,r=m,ans=m;
	while(l<r-1)
	{
		ll mid=(l+r)/2;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(ans>2&&check(ans-2))cout<<ans-2<<endl;
	else if(ans>1&&check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}
/*
1 2 3
1 1 1 2
*/