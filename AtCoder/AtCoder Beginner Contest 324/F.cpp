#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define double long double
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
struct Edge{
	int to,next;ll w,c;
}edge[maxn];
int head[maxn],cnt;
double dis[maxn];
int in[maxn];
int out[maxn];
int n,m;
void add(int from,int to,ll w,ll c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool check(double mid)
{
	for(int i=1;i<=n;i++)
		dis[i]=-1e18;
	dis[1]=0;
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			ll w=edge[i].w;
			ll c=edge[i].c;
			double now=w-1.0*c*mid;
			dis[y]=max(dis[y],dis[x]+now);
		}
	}
	return dis[n]>=0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;ll w,c;
		cin>>x>>y>>w>>c;
		add(x,y,w,c);
	}
	double l=0,r=2e9;
	double eps=1e-10;
	while(r-l>eps)
	{
		double mid=0.5*(l+r);
		// cout<<l<<" "<<r<<" "<<mid<<" "<<endl;
		// _sleep(100);
		if(check(mid))l=mid;
		else r=mid;
	}
	cout << fixed << setprecision(15) <<l<<"\n";
	// cout<<check(0)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}