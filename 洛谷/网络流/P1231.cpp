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
struct Edeg{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n1,n2,n3;
int m1,m2;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*n);
	cnt=1;
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
			if(w&&!dep[y])
				dep[y]=dep[x]+1,q.push(y);
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
int in_a[maxn],out_a[maxn];
int in_b[maxn],out_b[maxn];
int in_c[maxn],out_c[maxn];
void solve()
{
	cin>>n1>>n2>>n3;
	init();
	s=n1*2+n2*2+n3*2+1;
	t=n1*2+n2*2+n3*2+2;
	for(int i=1;i<=n1;i++)
	{
		in_a[i]=++tot,out_a[i]=++tot;
		add(in_a[i],out_a[i],1);
		add(out_a[i],in_a[i],0);
	}
	for(int i=1;i<=n2;i++)
	{
		in_b[i]=++tot,out_b[i]=++tot;
		add(in_b[i],out_b[i],1);
		add(out_b[i],in_b[i],0);
		add(s,in_b[i],1);
		add(in_b[i],s,0);
	}
	for(int i=1;i<=n3;i++)
	{
		in_c[i]=++tot,out_c[i]=++tot;
		add(in_c[i],out_c[i],1);
		add(out_c[i],in_c[i],0);
		add(out_c[i],t,1);
		add(t,out_c[i],0);
	}
	cin>>m1;
	for(int i=1;i<=m1;i++)
	{
		int x,y;
		cin>>x>>y;
		add(out_b[y],in_a[x],1);
		add(in_a[x],out_b[y],0);
	}
	cin>>m2;
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		add(out_a[x],in_c[y],1);
		add(in_c[y],out_a[x],0);
	}
	cout<<DINIC(s,t)<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}