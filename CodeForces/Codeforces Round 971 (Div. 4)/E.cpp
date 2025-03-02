#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	ll n,k;
	cin>>n>>k;

	ll sum=(k+k+n-1)*n/2;
	ll l=1,r=n,ans=l;
	auto f=[&](ll mid)->ll{
		return 1ll*(k+k+mid-1)*mid/2;
	};
	auto check=[&](ll mid)->bool{
		return f(mid)<=(sum-f(mid));
	};

	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(ans<n&&check(ans+1))ans++;

	ll res = abs(f(ans)*2-sum);
	if(ans>1)res=min(res,abs(f(ans-1)*2-sum));
	if(ans<n)res=min(res,abs(f(ans+1)*2-sum));
	cout<<res<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}