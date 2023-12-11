/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
#define endl "\n"
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dep[maxn];
int n,m,s,t;
void init(){
	memset(head+1,0,sizeof(int)*t);
	cnt=1;
}
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*t);
	queue<int>q;
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(w&&dep[y]==0)
			{
				dep[y]=dep[x]+1;
				q.push(y);
			}
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
		if(w&&dep[y]==dep[x]+1)
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
	while(cin>>n>>m)
	{
		s=n+m+1;
		t=n+m+2;
		init();
		for(int i=1,t;i<=n;i++)
		{
			cin>>t;
			for(int j=1,x;j<=t;j++)
			{
				cin>>x;x+=n;
				add(i,x,1);
				add(x,i,0);
			}
		}
		for(int i=1;i<=n;i++)
		{
			add(s,i,1);
			add(i,s,0);
		}
		for(int i=1;i<=m;i++)
		{
			add(i+n,t,1);
			add(t,i+n,0);
		}
		cout<<DINIC(s,t)<<endl;
	}
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}