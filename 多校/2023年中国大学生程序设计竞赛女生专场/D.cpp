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
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void Add(int from,int to,int w,int c)
{
	add(from,to,w,c);
	add(to,from,0,-c);
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*tot);
	memset(last+1,-1,sizeof(int)*tot);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
int MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=min(0,flow[t]*dis[t]);
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	// cout<<maxf<<" "<<maxc<<endl;
	// cout<<-maxc<<endl;
	// cout<<max(0,-maxc)<<endl;
	return -maxc;
}
const int N=100;
int mp[N][N];
int out[N][N];
int in[N][N];
pii p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			in[i][j]=++tot,out[i][j]=++tot;
			if(mp[i][j]==1)
				Add(in[i][j],out[i][j],1,0);
			else if(mp[i][j]==0)
				Add(in[i][j],out[i][j],1,1);
		}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int k=0;k<4;k++){
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||y<1||x>n||y>m)continue;
				Add(out[i][j],in[x][y],1,0);
			}
		}
	}
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		Add(s,in[x][y],1,-100);
	}
	ll ans=0;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		Add(out[x][y],t,1,0);
		// cout<<MCMF(s,t)<<endl;
		// ans+=max(0,MCMF(s,t));
	}
	cout<<MCMF(s,t)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}