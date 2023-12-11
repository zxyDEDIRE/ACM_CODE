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
const int INF=1e9+3;
const int maxn=1e6+100;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

ll f()
{
	int n;
	cin>>n;
	ll x=1;
	while(n--)
	{
		ll op,w;
		cin>>op>>w;
		if(op==1)x=(x*w)%mod;
		else x=(x*ksm(w,mod-2))%mod;
	}
	return x;
}
void solve()
{
	ll a=f();
	ll b=f();
	if(a==b)cout<<"YES\n";
	else cout<<"NO\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}