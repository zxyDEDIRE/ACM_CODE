#include<bits/stdc++.h>
#define int long long
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e6+7;
int head[maxn],cnt;
bool vis[maxn];
int dis[maxn];
int in[maxn];
int n,m;
struct Edge{
	int to,next,w;
}edge[maxn];
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int spfa(int sa)
{
	memset(dis,INF,sizeof(dis));
	queue<int>q;
	q.push(sa);
	dis[sa]=0;
	vis[sa]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
	//	cout<<x<<endl;
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				if(!vis[y])
				{
					in[y]++;
					if(in[y]==n)return -1;
					vis[y]=1;q.push(y);
				}
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1,u,v,w;i<=m;i++){
		cin>>u>>v>>w;
		add(v,u,w);
	}
	for(int i=1;i<=n;i++)add(0,i,0);
	spfa(0);
	int mi=INF;
	for(int i=1;i<=n;i++)mi=min(mi,dis[i]);
	for(int i=1;i<=n;i++)cout<<dis[i]-mi<<endl;
}
