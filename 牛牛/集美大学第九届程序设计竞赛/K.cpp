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
}
using namespace Flow;
int a[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		p[i]=++tot;
		Add(s,p[i],1);
	}
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		Add(p[x],tot+1,a[x]);
		p[x]=++tot;
		Add(p[y],tot+1,a[y]);
		p[y]=++tot;
		// Add(s,p[x],1);
		// Add(s,p[y],1);
		add(p[x],p[y],1);
		add(p[y],p[x],1);
	}
	Add(p[1],t,a[1]);
	cout<<DINIC()<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}