/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<algorithm>
#include<bitset>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define endl "\n"
#define int long long
const int INF=1e9+7;
const int maxn=1e5;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int d[maxn],q[maxn];
bitset<maxn>vis;
int n,m,s,t;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int dfs(int x,int flow)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&d[y]==d[x]+1)
		{
			int tmp=dfs(y,min(out,w));
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)d[x]=0;
	return flow-out;
}
bool makelevel(int s,int t)
{
	for(int i=0;i<=n;i++)
		d[i]=0;
	queue<int>q;
	d[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(d[y]==0&&w>0)
			{
				q.push(y);
				d[y]=d[x]+1;
			}
		}
	}
	return false;
}
void solve()
{
	while(cin>>m>>n)
	{
		s=1,t=n;
		for(int i=1;i<=n;i++)
			head[i]=0;
		cnt=1;
		for(int i=1;i<=m;i++)
		{
			int x,y,w;
			cin>>x>>y>>w;
			add(x,y,w);
			add(y,x,0);
		}
		int ans=0;
		while(makelevel(s,t))
		{
			ans+=dfs(s,INF);
		}
		cout<<ans<<endl;
	}
	
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}