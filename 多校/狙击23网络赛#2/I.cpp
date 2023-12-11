/*！*/
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
const int N=2e3+11;
struct node{
	int id;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next;ll w;
}edge[maxn];
int head[maxn],cnt;
array<int,3>p[maxn];
bitset<N>vis;
ll dis[N][N];
int n,m,c;
ll ans=INF;
void add(int from,int to,ll w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[s][i]=INF;
	vis.reset();
	priority_queue<node>q;
	q.push({s,0});
	dis[s][s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[s][y]>dis[s][x]+w)
			{
				dis[s][y]=dis[s][x]+w;
				q.push({y,dis[s][y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>c;
	ll mi_cost=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		p[i]={x,y,w};
		mi_cost = min(mi_cost,1ll*w);
	}
	for(int i=1;i<=n;i++)
		dij(i);
	ll mi=INF;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=p[i];
		mi = min(mi, dis[y][x]+w);
	}
	if(mi_cost>c)cout<<0<<endl;
	else if(mi<=c)cout<<2<<endl;
	else cout<<1<<endl;
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
https://zhuanlan.zhihu.com/p/342293693
*/