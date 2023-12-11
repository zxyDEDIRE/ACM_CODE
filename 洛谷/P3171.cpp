/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e18;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
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
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*tot);
	queue<int>q;
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dep[y]==0&&w>0)
				q.push(y),dep[y]=dep[x]+1;
		}
	}
	return false;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct E{
	int to,next,w;
}e[maxn];
bitset<maxn>vis;
int h[maxn],cn;
const int N=1000;
vector<pii>G[N];
int dis[N];
int out[N];
int in[N];
int ru[N];
void ad(int from,int to,int w)
{
	e[++cn].to=to;
	e[cn].w=w;
	e[cn].next=h[from];
	h[from]=cn;
}
void solve()
{
	init();
	cin>>n>>m;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		out[i]=++tot;
		in[i]=++tot;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		ad(x,y,w);
		ad(y,x,w);
	}
	for(int x=1;x<=n;x++)
	{
		int w;cin>>w;
		add(in[x],out[x],w);
		add(out[x],in[x],0);
	}
	add(s,out[1],INF);
	add(out[1],s,0);


	add(in[n],t,INF);
	add(t,in[n],0);


	priority_queue<node>q;
	for(int i=1;i<=n;i++)dis[i]=INF;
	vis.reset();
	dis[1]=0;
	q.push({1,0});
	while(!q.empty())
	{
		auto [x,X]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=h[x];i;i=e[i].next)
		{
			int y=e[i].to;
			if(dis[y]>dis[x]+e[i].w)
			{
				ru[y]++;
				dis[y]=dis[x]+e[i].w;
				q.push({y,dis[y]});
			}
			if(dis[y]==dis[x]+e[i].w)
			{
				G[y].push_back({x,e[i].w});
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<dis[i]<<" ";cout<<endl;
	for(int x=1;x<=n;x++)
	{
		for(auto [y,w]:G[x])
		{
			if(dis[y]+w==dis[x])
			{
				//cout<<y<<" "<<x<<endl;
				add(out[y],in[x],INF);
				add(in[x],out[y],0);
			}
		}
	}
	cout<<DINIC(s,t)<<endl;



}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}