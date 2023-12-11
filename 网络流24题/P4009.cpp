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
const int INF=1e9+7;
const int maxn=1e7;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,s,t,tot;
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
void MCMF(int s,int t)
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
	cout<<maxf<<endl;
	cout<<maxc<<endl;
}
const int N=200;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bitset<N>ok[N];
int out[N][N][11];
int in[N][N][11];
int mp[N][N];
int k,a,b,c;
void bfs(int X,int Y)
{ 
	//cout<<X<<" "<<Y<<endl;
	queue<pii>q;
	for(int i=1;i<=n;i++)
		ok[i].reset();
	q.push({X,Y});
	ok[X][Y]=1;
	while(!q.empty())
	{
		auto [x,y]=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>n||ok[xx][yy])continue;
			ok[xx][yy]=1;
			int dis=abs(X-xx)+abs(Y-yy);
			if(dis>k)continue;
			int cost=0;
			if(xx<X)cost+=X-xx;
			if(yy<Y)cost+=Y-yy;
			//cout<<xx<<"  "<<yy<<endl;
			for(int j=k;j-dis>=0;j--)
			{
				add(out[X][Y][j],in[xx][yy][j-dis],INF,cost);
				add(in[xx][yy][j-dis],out[X][Y][j],0,-cost);
			}
			if(mp[xx][yy]==0)
			{
				q.push({xx,yy});
			}
		}
	}
	//cout<<endl;
}
void solve()
{
	init();
	cin>>n>>k>>a>>b>>c;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int ii=0;ii<=k;ii++)
			{
				in[i][j][ii]=++tot;
				out[i][j][ii]=++tot;
				// if(ii>0)
				// {
				// 	add(in[i][j][ii],out[i][j][ii-1],INF,0);
				// 	add(out[i][j][ii-1],in[i][j][ii],0,0);
				// }
			}
			int x;cin>>x;
			mp[i][j]=x;
			if(x==1)
			{
				for(int ii=0;ii<=k;ii++)
				{
					add(in[i][j][ii],out[i][j][k],INF,a);
					add(out[i][j][k],in[i][j][ii],0,-a);
				}
			}
			else
			{
				if(i==1&&j==1)
				{
					add(s,out[1][1][k],1,0);
					add(out[1][1][k],s,0,0);
				}
				else if(i==n&&j==n)
				{
					for(int ii=0;ii<=k;ii++)
					{
						add(in[n][n][ii],t,1,0);
						add(t,in[n][n][ii],0,0);
					}
				}
				else
				{
					for(int ii=0;ii<=k;ii++)
					{
						add(in[i][j][ii],out[i][j][k],INF,a+c);
						add(out[i][j][k],in[i][j][ii],0,-(a+c));
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			bfs(i,j);
		}
	}
	MCMF(s,t);
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4 4 1 10 100 
0 0 0 0
0 0 0 0
0 0 0 0
0 0 0 0

100*100*10

*/