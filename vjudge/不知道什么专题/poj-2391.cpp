/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e18;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
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
	memset(dep+1,0,sizeof(int)*t);
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
int dis[222][222];
int a[maxn],b[maxn];
int sum=0;
bool check(int mid)
{
	s=n+n+1;
	t=n+n+2;
	init();
	for(int i=1;i<=n;i++)
	{
		add(s,i,a[i]);
		add(i,s,0);

		add(i+n,t,b[i]);
		add(t,i+n,0);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(dis[i][j]<=mid){
				add(i,j+n,INF);
				add(j+n,i,0);
			}
	int ans=DINIC(s,t);
	if(ans>=sum)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			dis[i][j]=INF;
			if(i==j)dis[i][j]=0;
		}
	sum=0;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i],sum+=a[i];
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		dis[x][y]=min(dis[x][y],w);
		dis[y][x]=min(dis[y][x],w);
	}
	int ma=0;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			ma=max(ma,dis[i][j]);
	int l=0,r=ma+10,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	cout<<ans<<endl;
	if(ans==ma+10)cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}
/*
2 2
2 4
2 3 
1 2 10
2 1 10
*/