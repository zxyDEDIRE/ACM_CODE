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
ll n;
void solve()
{
	cin>>n;
	ll h=log2(n);
	if((1ll<<h)<=n)h++;
	
	ll ans=0;
	n++;
	// cout<<h<<" "<<(1ll<<h)<<endl;
	for(int i=h;i>=0;i--)
	{
		ll T=(1ll<<(i+1));
		ll S=(1ll<<i);

		ll x=n/T;
		ll y=n%T;
		ans+=x*S;
		ans+=max(0ll,y-S);
	}
	cout<<ans<<endl;


	// for(int i=0;i<=n;i++)
	// {
	// 	bitset<8>a(i);
	// 	cout<<a<<endl;
	// }
	/*
	0 2
	1 4
	*/
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