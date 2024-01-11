#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=1e3+10;
struct Node{
	ll id,c,dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[N];
bool vis[N][N];
ll dis[N][N];
ll s[N];
int n,m;
void dij()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=1000;j++)
			dis[i][j]=INF,vis[i][j]=0;
	dis[1][s[1]]=0;
	priority_queue<Node>q;
	q.push({1,s[1],0});
	while(!q.empty())
	{
		auto [x,c,DIS]=q.top();q.pop();
		if(vis[x][c])continue;
		vis[x][c]=1;
		for(auto [y,w]:v[x])
		{
			int _c=min(c,s[y]);
			int _w=c*w;
			if(dis[y][_c]>dis[x][c]+_w)
			{
				dis[y][_c]=dis[x][c]+_w;
				q.push({y,_c,dis[y][_c]});
			}
		}
	}
	ll mi=INF;
	for(int i=1;i<=1000;i++)
		mi=min(mi,dis[n][i]);
	cout<<mi<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=m;i++)
	{
		ll x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	for(int i=1;i<=n;i++)
		cin>>s[i];
	dij();
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