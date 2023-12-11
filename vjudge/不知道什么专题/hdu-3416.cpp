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
const int INF=1e9+7;
const int maxn=4e5+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
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
		// memset(dep+1,0,sizeof(int)*tot);
		// queue<int>q;
		// dep[s]=1;
		// q.push(s);
		// while(!q.empty())
		// {
		// 	int x=q.front();q.pop();
		// 	if(x==t)return true;
		// 	for(int i=head[x];i;i=edge[i].next)
		// 	{
		// 		int y=edge[i].to;
		// 		int w=edge[i].w;
		// 		if(dep[y]==0&&w>0)
		// 			q.push(y),dep[y]=dep[x]+1;
		// 	}
		// }
		// return false;
		memset(dep+1,0x3f,sizeof(int)*tot);
		queue<int>q;
		q.push(s);
		dep[s]=0;
		now[s]=head[s];
		while(!q.empty()){
			int x=q.front();q.pop();
			for(int i=head[x];i;i=edge[i].next){
				int y=edge[i].to;
				if(edge[i].w>0&&dep[y]==inf){
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
		// if(x==t)return flow;
		// int out=flow;
		// for(int i=head[x];i;i=edge[i].next)
		// {
		// 	int y=edge[i].to;
		// 	int w=edge[i].w;
		// 	if(w!=0&&dep[y]==dep[x]+1)
		// 	{
		// 		int tmp=dfs(y,min(out,w),t);
		// 		edge[i].w-=tmp;
		// 		edge[i^1].w+=tmp;
		// 		out-=tmp;
		// 		if(!out)break;
		// 	}
		// }
		// if(out==flow)dep[x]=0;
		// return flow-out;
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
}
struct Edge{
	int to,next,w;
}edge1[maxn],edge2[maxn];
int head1[maxn],head2[maxn],cnt1,cnt2;
bitset<maxn>vis,ok;
int dis[maxn];
int n,m,s,t;
void init()
{
	for(int i=1;i<=n;i++)
		head1[i]=head2[i]=0;
	cnt1=cnt2=0;
}
void add(int from,int to,int w)
{
	edge1[++cnt1].w=w;
	edge1[cnt1].to=to;
	edge1[cnt1].next=head1[from];
	head1[from]=cnt1;
}
void add1(int from,int to,int w)
{
	edge2[++cnt2].w=w;
	edge2[cnt2].to=to;
	edge2[cnt2].next=head2[from];
	head2[from]=cnt2;
}
void dij(int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF,vis[i]=ok[i]=0;
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head1[x];i;i=edge1[i].next)
		{
			int y=edge1[i].to;
			int w=edge1[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
	queue<int>st;
	st.push(t);
	while(!st.empty()){
		int x=st.front();st.pop();
		if(ok[x])continue;
		ok[x]=1;
		for(int i=head2[x];i;i=edge2[i].next)
		{
			int y=edge2[i].to;
			int w=edge2[i].w;
			if(dis[y]+w==dis[x]){
				if(x!=y)
					Flow::Add(y,x,1);
				// cout<<"P:"<<y<<" "<<x<<endl;
				st.push(y);
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	init();
	Flow::init();
	Flow::s=n+1;
	Flow::t=n+2;
	Flow::tot=n+2;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		if(x==y)continue;
		add(x,y,w);
		add1(y,x,w);
	}
	cin>>s>>t;
	Flow::Add(Flow::s,s,INF);
	Flow::Add(t,Flow::t,INF);
	dij(s,t);
	cout<<Flow::DINIC()<<endl;
}
signed main(){
	int size(512<<20); // 512M
    __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size)); // YOUR CODE
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	exit(0);
	return 0;
}