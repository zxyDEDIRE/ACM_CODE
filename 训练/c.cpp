#include<bits/stdc++.h>
using namespace std;
const int INF=1e9;
const int maxn=1e6;
struct node{
	int x,y;
	bool operator<(const node &a)const{
		return a.y<y;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int b[maxn];
int n,m,t,mi,q;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void bfs()
{
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[t]=0;
	mi=INF;
	priority_queue<node>q;
	q.push(node{t,0});
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.x;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
	for(int i=1;i<=m;i++)
		mi=min(mi,dis[b[i]]);
}
bool check(int mid)
{
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[t]=0;
	priority_queue<node>q;
	q.push(node{t,0});
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.x;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			if(edge[i].w>mid)continue; 
			int y=edge[i].to;
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
	int W=INF;
	for(int i=1;i<=m;i++)
		W=min(W,dis[b[i]]);
	return W==mi;
}
int main()
{
	cin>>n>>m>>t;
	for(int i=1,x;i<=m;i++)
		cin>>b[i];
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	bfs();
	if(mi==INF){
		cout<<-1<<endl;
		return 0;
	}
	int l=0,r=2e5,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(check(ans-1)&&ans-1>=0)ans--;
	cout<<ans+mi<<endl;
	
}