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
ll a[maxn];
int n,p,P;
void solve()
{
	cin>>n>>p>>P;


	auto f=[&](ll sum,ll x)->ll{
		ll now=((p)/P);
		ll t=(P-sum%P)%P;
		if(t==0) t=p;
		if(t<=p%P)now++;
		if((sum+x)%P==0&&x<=p)now--;
		return now;
	};

	ll sum=0;
	for(int i=1;i<=n;i++)
		cin>>a[i],sum+=a[i];
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		sum-=a[i];
		ll now=f(sum,a[i]);
		cout<<i<<" "<<now<<endl;
		ans+=now;
		sum+=a[i];
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