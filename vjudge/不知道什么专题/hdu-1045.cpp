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
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*n);
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
	memset(dep+1,0,sizeof(int)*n);
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
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bool vis[100][100];
char mp[100][100];
int X[100][100];
int Y[100][100];
int tot=0;
void dfs_1(int x,int y,int fl,int c)
{
	if(mp[x][y]=='X')return ;
	if(y>n)return ;
	vis[x][y]=1;
	if(fl==1)X[x][y]=c;
	else Y[x][y]=c;
	if(fl==1)dfs_1(x,y+1,fl,c);
	else dfs_1(x+1,y,fl,c);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	s=++tot;
	t=++tot;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j])continue;
			dfs_1(i,j,1,++tot);
		}
	}
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(vis[i][j])continue;
			dfs_1(i,j,2,++tot);
		}
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}