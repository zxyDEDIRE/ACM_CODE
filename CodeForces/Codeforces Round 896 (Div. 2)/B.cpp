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
const ll INF=1e18+7;
const int maxn=1e6+100;
pii p[maxn];
int n,k,a,b;
ll f(int x,int y){
	return abs(p[x].first-p[y].first)+abs(p[x].second-p[y].second)*1ll;
}
void solve()
{
	cin>>n>>k>>a>>b;
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	ll ma=INF,mb=INF;
	ll ans=f(a,b);

	if(a<=k)ma=0;
	if(b<=k)mb=0;
	for(int i=1;i<=k;i++)
	{
		if(i!=a)ma=min(ma,f(i,a));
		if(i!=b)mb=min(mb,f(i,b));
	}
	ans=min(ans,ma+mb);
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