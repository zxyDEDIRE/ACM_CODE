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
pii MCMF(int s,int t)
{
	int maxf=0,maxc=0;
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
	// cout<<maxf<<" "<<maxc<<endl;
	return {maxf,maxc};
}
const int N=2222;
int a[N][N],b[N][N],c[N][N],in[N][N][3];
int n,m;
void solve()
{
	cin>>n>>m;
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>b[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<3;k++)
				in[i][j][k]=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if((i+j)&1)
			{
				Add(s,in[i][j][0],1,0);
				Add(in[i][j][0],in[i][j][1],1,0);
				Add(in[i][j][0],in[i][j][2],1,c[i][j]);
				for(int k=0;k<4;k++)
				{
					int xx=i+dx[k];
					int yy=j+dy[k];
					if(xx<1||yy<1||xx>n||yy>m)continue;
					if(__gcd(a[i][j],a[xx][yy])==1)
						Add(in[i][j][1],in[xx][yy][1],1,0);
					if(__gcd(a[i][j],b[xx][yy])==1)
						Add(in[i][j][1],in[xx][yy][2],1,0);
					if(__gcd(b[i][j],a[xx][yy])==1)
						Add(in[i][j][2],in[xx][yy][1],1,0);
					if(__gcd(b[i][j],b[xx][yy])==1)
						Add(in[i][j][2],in[xx][yy][2],1,0);
				}
			}
			else
			{
				Add(in[i][j][0],t,1,0);
				Add(in[i][j][1],in[i][j][0],1,0);
				Add(in[i][j][2],in[i][j][0],1,c[i][j]);
			}
		}
	}
	auto [f,c]=MCMF(s,t);
	if(f*2!=n*m)cout<<-1<<endl;
	else cout<<c<<endl;
	cout<<"FFFFFFFFFF";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	// string str;
	// cin>>str;
	// cout<<str<<endl;
	// cout<<"OK!"<<endl;
	return 0;
}/*

for %%a in (c) do for /f "delims=" %%i in ('wsl pwd') do (set "var=%%i")
*/
