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
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll ksm(ll b,ll p,ll mod){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll f[maxn];
int p,A,n;
void solve()
{
	cin>>f[1]>>f[2]>>p>>A>>n;
	for(int i=3;i<=n;i++)
	{
		f[i]=floor(log2(ksm(f[i-1],f[i-2],p)+1))+A;
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
		cout<<f[i]<<" \n"[i==n];
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}