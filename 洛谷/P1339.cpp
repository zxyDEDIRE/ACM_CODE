#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
const int INF=0x3f3f3f3f;
int n,m,s,t,res;
int dis[maxn];
int vis[maxn];
int cnt,head[maxn];
struct Edge{
	int to,next,w;
}edge[maxn];
void add(int from,int to,int w){
	edge[++cnt].to=to;
	edge[cnt].w=w;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
struct node{
	int id,dist;
	bool operator<(const node &a)const {return a.dist<dist;}
};
void dij()
{
	memset(dis,INF,sizeof(dis));
	priority_queue<node>q;
	dis[s]=0;
	q.push(node{s,0});
	while(!q.empty())
	{
		node top=q.top();q.pop();
		int x=top.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[x]+edge[i].w<dis[y]){
				dis[y]=dis[x]+edge[i].w;
				q.push(node{y,dis[y]});
			}
		}
	}
}
int main()
{
	cin>>n>>m>>s>>t;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij();
	cout<<dis[t]<<endl;
}