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
ll p[maxn];
ll n,m,d;
void solve()
{
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	multiset<ll>s;
	ll ans=0;
	ll sum=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]>0)
		{
			s.insert(p[i]);
			sum+=p[i];
		}
		if(s.size()>m)
		{
			sum-=*s.begin();
			s.erase(s.begin());
		}
		ans=max(ans,sum-d*i);
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