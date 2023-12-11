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
const int INF=1e18+7;
const int maxn=1e7;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*tot);
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
const int N=1000+7;
int out[N][N];
int in[N][N];
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			in[i][j]=++tot;//,out[i][j]=++tot;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int x;cin>>x;
			add(in[i][j],in[i][j+1],x);
			add(in[i][j+1],in[i][j],x);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;cin>>x;
			add(in[i][j],in[i+1][j],x);
			add(in[i+1][j],in[i][j],x);
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int x;cin>>x;
			add(in[i][j],in[i+1][j+1],x);
			add(in[i+1][j+1],in[i][j],x);
		}
	}
	add(s,in[1][1],INF);
	add(in[1][1],s,0);
	add(in[n][m],t,INF);
	add(t,in[n][m],0);
	cout<<DINIC(s,t)<<endl;
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