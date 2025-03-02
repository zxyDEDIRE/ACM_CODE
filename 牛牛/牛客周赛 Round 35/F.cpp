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
int p[maxn];
int a[maxn];
int b[maxn];
int n;
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll ksm(ll b,ll p,ll mod){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}

void solve()
{
	cin>>n;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		if(p[i]==2)a[i]++;
		if(p[i]==3)b[i]++;
		sum+=b[i];
	}
	ll ans=ksm(2,n);
	ans=(ans-1+mod)%mod;
	for(int i=1;i<=n;i++)
	{
		ll _a=(a[i]*b[i]+a[i]+b[i])%mod*ksm(2,n-1)%mod;
		ll _b=a[i]*(sum-b[i])%mod*ksm(2,n-2)%mod;
		ans=(ans+(_a+_b)%mod)%mod;
	}
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
6
2 2 2 3 2 3
*/