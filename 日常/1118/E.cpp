#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF=1e9+7;
const int maxn=1e6;
const int N=200;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
bitset<N>a,b;
string mp[N];
int n,m,num_a,num_b,tot,s,t;
void init()
{
	memset(head+1,0,sizeof(int)*tot);
	a.reset();
	b.reset();
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
bool ok(int x,int y)
{
	if(x<1||x>n||y<1||y>m||mp[x][y]=='1')return 0;
	return 1;
}
int in[N][N];
int out[N][N];
void add(int x,int y)
{
	add(x,y,1);
	add(y,x,0);
	add(y,x,1);
	add(x,y,0);
}
void solve()
{
	cin>>n>>m>>num_a>>num_b;
	init();
	for(int i=1;i<=n;i++)
		cin>>mp[i],mp[i]=" "+mp[i];
	for(int i=1,x;i<=num_a;i++)
		cin>>x,a[x]=1;
	for(int i=1,x;i<=num_b;i++)
		cin>>x,b[x]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			in[i][j]=++tot,out[i][j]=++tot;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!ok(i,j))continue;
			if(ok(i-1,j))
				add(in[i-1][j],in[i][j]);
			if(ok(i,j-1))
				add(out[i][j-1],out[i][j]);
			add(in[i][j],out[i][j]);
		}
	}
	for(int i=1;i<=m;i++)
	{	
		if(a[i])
		{
			add(s,in[1][i],1);
			add(in[1][i],s,0);
		}
		if(b[i])
		{
			add(in[n][i],t,1);
			add(t,in[n][i],0);
		}
	}
	int ans=DINIC(s,t);
	if(ans==num_a)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
}
/*
2
3 4 2 2
0000
0011
0000
1 4
2 4
3 4 2 2
0000
0011
0000
3 4
2 4
*/