/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
int n,m,s,t,tot;
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
	cout<<maxc<<endl;
}
const int N=200;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bitset<N>ok[N];
int out[N][N];
int in[N][N];
int mp[N][N];
int k,a,b,c;
void INIT()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ok[i][j]=0;
}
void dfs(int x,int y,int fx,int fy,int cost)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>n||ok[xx][yy])continue;
		int dis=abs(xx-fx)+abs(yy-fy);
		if(dis>k)continue;


		int cos=cost;
		if(xx<x)cos++;
		if(yy<y)cos++;

		add(out[fx][fy],in[xx][yy],INF,cos*b);
		add(in[xx][yy],out[fx][fy],0,-cos*b);

		if(!mp[xx][yy])
		{
			ok[xx][yy]=1;
			dfs(xx,yy,fx,fy,cos);
		}
	}
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
			in[i][j]=++tot;
			out[i][j]=++tot;

			int x;
			cin>>x;
			mp[i][j]=x;
			if(x==1)
			{
				add(in[i][j],out[i][j],INF,a);
				add(out[i][j],in[i][j],0,-a);
			}
			else
			{
				if(i==1&&j==1)
				{
					add(s,out[1][1],1,0);
					add(out[1][1],s,0,0);
				}
				else if(i==n&&j==n)
				{
					add(in[n][n],t,1,0);
					add(t,in[n][n],0,0);
				}
				else
				{
					add(in[i][j],out[i][j],INF,a+c);
					add(out[i][j],in[i][j],0,-(a+c));
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			INIT();
			ok[i][j]=1;
			dfs(i,j,i,j,0);
		}
	}
	cout<<"Yes"<<endl;
	MCMF(s,t);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}