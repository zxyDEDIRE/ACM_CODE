#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=2e3;
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
	memset(in,0,sizeof(in));
	memset(vis,0,sizeof(vis));
	memset(dis,0,sizeof(dis));
	queue<int>q;
	q.push(sa);
	vis[sa]=1;dis[sa]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		cout<<x<<endl;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				if(!vis[y])
				{
					vis[y]=1;in[y]++;
					if(in[y]>n)return 0;
					q.push(y);
				}
			}
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	cnt=0;
	for(int i=1;i<=n;i++)add(0,i,0);
	for(int i=1,u,v,w;i<=m;i++)
	{
		cin>>u>>v>>w;
		add(u-1,v,-w);
		add(v,u-1,w);
	}
	if(spfa(0))cout<<"true"<<endl;
	else cout<<"false"<<endl;
}
signed main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
abc
b-a==c
b-a<=c
b-a>=c
a-b<

1
3 3
1 2 10
1 3 -5
3 3 -15

0 0 10 -5
*/
