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
	int to,next,w;double c;
}edge[maxn];
int head[maxn],cnt;
double dis[maxn];
int flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
inline void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
inline void add(const int from,const int to,const int w,const double c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
inline void Add(const int from,const int to,const int w,const double c)
{
	add(from,to,w,c);
	add(to,from,0,-c);
}
inline bool spfa(const int s,const int t)
{
	for(int i=1;i<=tot;i++){
		dis[i]=INF;
		last[i]=-1;
		vis[i]=0;
	}
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			double c=edge[i].c;
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
inline void MCMF(const int s,const int t)
{
	double maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	if(maxf!=n-1)cout<<-1<<endl;
	else cout << fixed << setprecision(10)<<maxc<<endl; 
}
struct node {
    int x,y;
}p[maxn];
inline double d(const int u,const int v){
	return sqrt((double)(p[u].x-p[v].x)*(p[u].x-p[v].x)+(p[u].y-p[v].y)*(p[u].y-p[v].y));
}
inline void f(const int u,const int v)
{
	Add(u*2-1,v*2,1,d(u,v));
}
void solve()
{
	cin>>n;
	init();
	s=n*2+1;
	t=s+1;
	tot=t;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].x>>p[i].y;
		Add(s,i*2-1,2,0);
		Add(i*2,t,1,0);
	}
	sort(p+1,p+1+n,[&](const node a,const node b){
		return a.y<b.y;
	});
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(p[j].y>p[i].y)
				f(j,i);
	MCMF(s,t);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}