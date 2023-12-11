/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<bitset>
using namespace std;
#define endl "\n";
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,k,s,t;
void init(){
	cnt=1;
	// memset(head+1,0,sizeof(int)*t);
	// memset(dep,0,sizeof(deep));
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
void solve()
{
	cin>>n>>m>>k;
	s=n*2+m+k+1;
	t=n*2+m+k+2;
	init();
	for(int i=1;i<=n;i++)
	{
		int a,b,x;
		cin>>a>>b;
		while(a--){
			cin>>x;
			x+=n*2;
			add(x,i,1);add(i,x,0);
		}
		while(b--){
			cin>>x;
			x+=n*2+m;
			add(i+n,x,1);add(x,i+n,0);
		}
	}
	for(int i=1;i<=n;i++)
		add(i,i+n,1),add(i+n,i,0);
	for(int i=1;i<=m;i++)
		add(s,2*n+i,1),add(2*n+i,s,0);
	for(int i=1;i<=k;i++)
		add(2*n+m+i,t,1),add(t,2*n+m+i,0);
	cout<<DINIC(s,t)<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}