#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using ld=long double;
using pdd=pair<long double,long double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
pii p[maxn];
ll n,k;
ll f(ld x,ld y)
{
	auto check=[&](ll mid)->bool{
		ld ans=0;
		for(int i=1;i<=n;i++)
		{
			auto [_x,_y]=p[i];
			if(_x>x+mid*0.5)ans+=_x-(x+mid*0.5);
			if(_x<x-mid*0.5)ans+=(x-mid*0.5)-_x;
			if(_y>y+mid*0.5)ans+=_y-(y+mid*0.5);
			if(_y<y-mid*0.5)ans+=(y-mid*0.5)-_y;
		}
		return ans<=k;
	};
	ll l=1,r=1e18,ans=r;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans&&check(ans-1))ans--;
	return ans;
}
void solve()
{
	cin>>n>>k;
	double X=0,Y=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
		X+=p[i].first;
		Y+=p[i].second;
	}
	X/=n;Y/=n;
	// cout<<X<<" "<<Y<<endl;
	ll ans=1e18;
	for(long double i=-0.5;i<=1;i+=0.5)
		for(long double j=-0.5;j<=1;j+=0.5)
			ans=min(ans,f(i,j));
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1436915220
484373824
*/