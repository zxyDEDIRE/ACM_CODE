/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
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
const int maxn=1e6;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt=1;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init()
{
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
			if(w&&dis[y]>dis[x]+c)
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
int in[111][111][11];
int k,a,b,c;
void solve()
{
	init();
	cin>>n>>k>>a>>b>>c;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int I=0;I<=k;I++)
				in[i][j][I]=++tot;
	s=++tot;
	t=++tot;
	add(s,in[1][1][k],1,0);
	add(in[1][1][k],s,0,0);

	for(int i=0;i<=k;i++)
	{
		add(in[n][n][i],t,1,0);
		add(t,in[n][n][i],1,0);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			int fl;
			cin>>fl;
			if(fl)
			{
				for(int I=0;I<k;I++)
				{
					add(in[i][j][I],in[i][j][k],1,a);
					add(in[i][j][k],in[i][j][I],0,-a);
				}
				if(i<n){
					add(in[i][j][k],in[i+1][j][k-1],1,0);
					add(in[i+1][j][k-1],in[i][j][k],0,0);}
				if(j<n){
					add(in[i][j][k],in[i][j+1][k-1],1,0);
					add(in[i][j+1][k-1],in[i][j][k],0,0);}
				if(i>1){
					add(in[i][j][k],in[i-1][j][k-1],1,b);
					add(in[i-1][j][k-1],in[i][j][k],0,-b);}
				if(j>1){
					add(in[i][j][k],in[i][j-1][k-1],1,b);
					add(in[i][j-1][k-1],in[i][j][k],0,-b);}
			}
			else
			{
				for(int I=0;I<k;I++)
				{
					add(in[i][j][I],in[i][j][k],1,a+c);
					add(in[i][j][k],in[i][j][I],0,-(a+c));
				}
				for(int I=1;I<=k;I++)
				{
					if(i<n){
						add(in[i][j][I],in[i+1][j][I-1],1,0);
						add(in[i+1][j][I-1],in[i][j][I],0,0);}
					if(j<n){
						add(in[i][j][I],in[i][j+1][I-1],1,0);
						add(in[i][j+1][I-1],in[i][j][I],0,0);}
					if(i>1){
						add(in[i][j][I],in[i-1][j][I-1],1,b);
						add(in[i-1][j][I-1],in[i][j][I],0,-b);}
					if(j>1){
						add(in[i][j][I],in[i][j-1][I-1],1,b);
						add(in[i][j-1][I-1],in[i][j][I],0,-b);}
				}
			}
		}
	}
	MCMF(s,t);
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}