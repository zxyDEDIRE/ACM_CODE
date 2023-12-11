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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll n,a,b,c;
ll f(ll x)
{
	ll r=n,l=1,ans=1;
	for(int i=1;i<=x;i++)
	{
		ans=(ans*r)%mod;
		ans=(ans*ksm(l,mod-2))%mod;
		r--;l++;
	}
	return ans;
}
void solve()
{
	cin>>n>>a>>b>>c;
	ll ans=ksm(2,n)-1;
	a=f(a);ans=(ans-a+mod)%mod;
	b=f(b);ans=(ans-b+mod)%mod;
	c=f(c);ans=(ans-c+mod)%mod;
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
10000000
34
5464
123
*/