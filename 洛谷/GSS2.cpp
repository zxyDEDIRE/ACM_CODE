//niiick
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
typedef long long lt;

lt read()
{
	lt f=1,x=0;
	char ss=getchar();
	while(ss<'0'||ss>'9'){if(ss=='-')f=-1;ss=getchar();}
	while(ss>='0'&&ss<='9'){x=x*10+ss-'0';ss=getchar();}
	return f*x;
}


const int maxn=800010;
int n,m,cnt;
lt Q,K,S;

struct node{int u, v;lt hi;}edge[maxn<<1];
bool cmp(node a,node b){return a.hi>b.hi;}

struct node2{int v,nxt;lt dis;}E[maxn<<1];
int head[maxn],tot;

lt d[maxn],vis[maxn],ff[maxn];
priority_queue< pair<lt,int> > q;

lt mi[maxn],val[maxn];
int gra[maxn][23];

void add(int u,int v,lt dis)
{
	E[++tot].nxt=head[u];
	E[tot].v=v; E[tot].dis=dis;
	head[u]=tot;
}

void dij()
{
	memset(vis,0,sizeof(vis));
	memset(d,111,sizeof(d)); d[1]=0;
	q.push(make_pair(0,1));

	while(!q.empty())
	{
		int u=q.top().second; q.pop();
		if(vis[u]) continue;

		vis[u]=1;
		for(int i=head[u];i;i=E[i].nxt)
		{
			int v=E[i].v;
			if(d[u]+E[i].dis<d[v])
			{
				d[v]=d[u]+E[i].dis;
				q.push(make_pair(-d[v],v));
			}
		}
	}
}

int find(int x)
{
	if(x==ff[x])return x;
	else return ff[x]=find(ff[x]);
}

void dfs(int u) 
{
	mi[u]=d[u];
	for(int i=head[u];i;i=E[i].nxt)
	{
		int v=E[i].v;
		gra[v][0]=u;
		dfs(v);
		mi[u]=min(mi[u],mi[v]);
	}
}

void kruskal()
{
	memset(head,0,sizeof(head)); tot=1;
	sort(edge+1,edge+1+m,cmp);
	for(int i=1;i<=n;++i)ff[i]=i; 
	for(int i=1;i<=m;i++) 
	{
		int fu=find(edge[i].u), fv=find(edge[i].v);
		if(fu!=fv)
		{
			val[++cnt]=edge[i].hi;
			ff[fu]=ff[fv]=ff[cnt]=cnt;
			add(cnt,fu,0); add(cnt,fv,0);
		}
	}
	dfs(cnt);
}
void init()
{
	memset(head,0,sizeof(head)); tot=1;
	memset(gra,0,sizeof(gra)); 
	memset(mi,111,sizeof(mi));
}
int main() 
{
	int T=read();
	while(T--) 
	{
		init();
		n=read();m=read();cnt=n;
		
		for(int i=1;i<=m;i++)
		{
			int u=read(),v=read(),dis=read(),hi=read();
			add(u,v,dis); add(v,u,dis);
			edge[i].u=u; edge[i].v=v; edge[i].hi=hi;
		}
		dij();//预处理1到所有节点最短路
		kruskal();//重构树
		
		for(int i=1;(1<<i)<=cnt;i++)
		for(int u=1;u<=cnt;u++)
		gra[u][i]=gra[gra[u][i-1]][i-1];
			
		for(int i=1;i<=n;i++)
			cout<<d[i]<<" ";cout<<endl;	
		for(int i=1;i<=cnt;i++)
			cout<<mi[i]<<" ";cout<<endl;
		// Q=read();K=read();S=read();
		// lt last=0;
		// while(Q--) 
		// {
		// 	int vi=read(),pi=read();
		// 	vi=(vi+K*last-1)%n+1;
		// 	pi=(pi+K*last)%(S+1);
			
		// 	for(int j=22;j>=0;--j)//找到深度最小且海拔大于水位的节点
		// 	if(gra[vi][j]&&val[gra[vi][j]]>pi) 
		// 	vi=gra[vi][j];
			
		// 	printf("%lld\n",last=mi[vi]);
		// }
	}
	return 0;
}
