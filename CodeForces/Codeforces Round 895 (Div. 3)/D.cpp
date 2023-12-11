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
ll n,x,y;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll lcm(ll x,ll y){
	return x*y/gcd(x,y);
}
void solve()
{
	cin>>n>>x>>y;
	ll z=lcm(x,y);
	ll l=floor(n/x)-floor(n/z);
	ll r=floor(n/y)-floor(n/z);
	// cout<<l<<" "<<r<<endl;
	ll ans=(n+(n-l+1))*l/2 - (1+r)*r/2;
	cout<<ans<<endl;
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