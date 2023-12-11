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
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=2;i<=n;i++)
		p[i]+=p[i-1];
	ll ans=0;
	for(int l=1;l<=n/2;l++)
	{
		if(n%l!=0)continue;
		ll mi=1e18;
		ll ma=0;
		for(int i=1;i+l-1<=n;i+=l)
		{
			ma=max(ma,p[i+l-1]-p[i-1]);
			mi=min(mi,p[i+l-1]-p[i-1]);
		}
		ans=max(ans,ma-mi);
	}
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
/*
16 1 2
*/