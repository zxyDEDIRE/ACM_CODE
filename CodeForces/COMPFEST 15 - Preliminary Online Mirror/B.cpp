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
const int maxn=2e6+100;
ll a[maxn],b[maxn];
ll p[maxn];
ll n,m;
ll ksm(ll b,ll p){ll r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>a[p[i]];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
		cin>>b[p[i]];
	ll ans=1;
	for(int i=1;i<=2e6;i++)
	{
		if(a[i]<b[i])ans=0;
		if(a[i]!=b[i])ans=mull(ans,2);
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
2 1 1 2 
2 3 5 7
  3   7
  1   1

2*1*2*2
*/