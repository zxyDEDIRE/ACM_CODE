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
ll pre[maxn];
ll p[maxn];
ll a[maxn];
int n,Q,T;
void solve()
{
	cin>>n>>Q>>T;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	ll mi=0,t=0;
	for(int i=1;i<=n;i++)
	{
		t+=p[i];
		a[i]=t;
		mi+=a[i];
	}
	pre[n+1]=0;
	for(int i=n;i>=1;i--)
		pre[i]+=pre[i+1];
	while(Q--)
	{
		ll x;
		cin>>x;
		ll y=x/T;
		y=min(y,1ll*n);
		cout<<a[n-y]+T<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}