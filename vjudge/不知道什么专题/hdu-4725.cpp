#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=8e5+100;
const int N=2e5+1000;
struct node{
	int id,dis;
	node(){};
	node(int a,int b):id(a),dis(b){}
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[N],cnt;
bitset<maxn>vis;
int dis[N];
int n,m,c;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	cnt=0;
	for(int i=1;i<=n*2;i++)
		head[i]=0;
}
void dij(int s)
{
	for(int i=1;i<=n*2;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>c;
	init();
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		add(x+n,i,0);
		if(x>1)add(i,x+n-1,c);
		if(x<n)add(i,x+n+1,c);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij(1);
	if(dis[n]==INF)cout<<"-1\n";
	else cout<<dis[n]<<"\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
/*
*/