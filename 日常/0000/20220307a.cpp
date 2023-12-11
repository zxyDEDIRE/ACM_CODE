#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<stdio.h> 
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int head[maxn],cnt;
bool vis[maxn];
int dis[maxn];
int in[maxn];
int n,mm,nn;
struct Edge{
	int to,next,w;
}edge[maxn];
int read() {
    int s = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
    while (isdigit(ch)) s = s * 10 + (ch ^ 48), ch = getchar();
    return f ? -s : s;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int spfa(int sa)
{
	memset(dis,INF,sizeof(dis));
	memset(vis,0,sizeof(vis));
	memset(in,0,sizeof(in));
	queue<int>q;
	q.push(sa);
	dis[sa]=0;vis[sa]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
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
					q.push(y);vis[y]=1;
				}
			}
		}
	}
	if(dis[n]==INF)return -2;
	else return dis[n];
}
signed main()
{
	cin>>n>>nn>>mm;
	for(int i=1,u,v,w;i<=nn;i++){
	//	cin>>u>>v>>w;
		u=read();v=read();w=read();
		add(u,v,w);
	}
	for(int i=1,u,v,w;i<=mm;i++){
	//	cin>>u>>v>>w;
		u=read();v=read();w=read();
		add(v,u,-w);
	}
	for(int i=1;i<n;i++)
		add(i+1,i,0);
	for(int i=1;i<=n;i++)
		add(0,i,0);
	int sp=spfa(0);
	if(sp<=-1)cout<<-1<<"\n";
	else cout<<spfa(1)<<"\n";
}
