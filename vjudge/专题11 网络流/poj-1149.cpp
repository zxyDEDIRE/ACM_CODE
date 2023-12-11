#include<iostream>
#include<algorithm>
#include<vector>
#include<bitset>
#include<cstring>
#include<queue>
using namespace std;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
namespace Flow{
	struct Edge{
		int to,next,w;
	}edge[maxn];
	int head[maxn],cnt=1;
	int dep[maxn];
	int now[maxn];
	int s,t,tot;
	void init(){
		memset(head+1,0,sizeof(int)*tot);
		cnt=1;
		tot=0;
	}
	void add(int from,int to,int w)
	{
		edge[++cnt].w=w;
		edge[cnt].to=to;
		edge[cnt].next=head[from];
		head[from]=cnt;
	}
	void Add(int u,int v,int w)
	{
		add(u,v,w);
		add(v,u,0);
	}
	bool bfs(int s,int t)
	{
		for(int i=1;i<=tot;i++)
			dep[i]=INF;
		queue<int>q;
		q.push(s);
		dep[s]=0;
		now[s]=head[s];
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=head[x];i;i=edge[i].next){
				int y=edge[i].to;
				if(edge[i].w>0&&dep[y]==INF){
					q.push(y);
					now[y]=head[y];
					dep[y]=dep[x]+1;
					if(y==t)return 1;
				}
			}
		}
		return 0;
	}
	int dfs(int x,int flow,int t)
	{
		if(x==t)return flow;
		int ans=0,k;
		for(int i=now[x];i&&flow;i=edge[i].next){
			now[x]=i;
			int y=edge[i].to;
			if(edge[i].w>0&&dep[y]==dep[x]+1){
				k=dfs(y,min(flow,edge[i].w),t);
				if(!k)dep[y]=inf;
				edge[i].w-=k;
				edge[i^1].w+=k;
				ans+=k;
				flow-=k;
			}
		}
		return ans;
	}
	int DINIC()
	{
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,INF,t);
		return ans;
	}
}using namespace Flow;
int to[maxn];
int a[maxn];
int n,m;
void solve()
{
	cin>>m>>n;
	init();
	tot=m;
	s=++tot;
	t=++tot;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		Add(s,i,a[i]);
		to[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		int now=++tot;
		int k,x,w;
		cin>>k;
		while(k--)
		{
			cin>>x;
			Add(to[x],now,INF);
			to[x]=++tot;
			Add(now,to[x],INF);
		}
		cin>>w;
		Add(now,t,w);
	}
	cout<<DINIC()<<endl;
	
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}