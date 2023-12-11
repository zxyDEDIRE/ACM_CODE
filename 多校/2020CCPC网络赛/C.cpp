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
int n,m,k;
void solve()
{
	ll ans=0;
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		cin>>p[i];
	sort(p+1,p+1+m);
	ans=k-1;
	ll ma=0;
	for(int i=1;i<=m;i++)
	{
		ans+=abs(k-p[i])*2;
	}
	// cout<<ans-abs(k-p[1])+p[1]-k<<endl;

	ll res=1e18;
	for(int i=1;i<=m;i++){
		ll val=ans-abs(k-p[i]);
		val+=p[i]-1;
		res=min(res,val);
	}
	cout<<res<<endl;
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


*/