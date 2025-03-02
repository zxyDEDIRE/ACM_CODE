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
ll a,b;
void solve()
{
	ll ans=0;
	cin>>a>>b;
	if(a>b)swap(a,b);
	while(a>0 && a!=b)
	{
		// cout<<a<<" "<<b<<endl;
		ll len=b-a+a-1;
		ll x=len/a;
		ans+=x;
		b-=x*a;
		if(a>b)swap(a,b);
	}
	if(a==b)ans++;
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