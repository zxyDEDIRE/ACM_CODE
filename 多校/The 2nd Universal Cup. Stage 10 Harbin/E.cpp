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
struct node{
	ll a,b,c,id,d,e;
}p[maxn];
ll B=0;
int n;
bool check(ll mid)
{
	for(int i=1;i<=n;i++)
		p[i].e=mid/p[i].c-B-p[i].a;
	sort(p+1,p+1+n,[&](node a,node b){
		if(a.d<=0 && b.d<=0)
			return a.e>b.e;
		if(a.d<=0 || b.d<=0)
			return a.d<b.d;
		return a.d+a.e<b.d+b.e;
	});
	ll sumb=0,ma=0;
	for(int i=1;i<=n;i++)
	{
		sumb+=p[i].d;
		ll now = (B + sumb + p[i].b)*p[i].c;
		ma=max(ma,now);
	}
	return ma<=mid;
}
void solve()
{
	cin>>n;
	B=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].a>>p[i].b>>p[i].c;
		B+=p[i].b;
		p[i].id=i;
		p[i].d=p[i].a-p[i].b;
	}
	ll l=0,r=1e18,ans=r;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(check(ans-1))ans--;
	check(ans);
	for(int i=1;i<=n;i++)
		cout<<p[i].id<<" \n"[i==n];
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