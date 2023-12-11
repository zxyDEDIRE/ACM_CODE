/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
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
struct Edeg{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*t);
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
int in[maxn],out[maxn];
int F[maxn],D[maxn];
int f,d;
void solve()
{
	cin>>n>>f>>d;
	init();
	s=f+d+n+n+1;
	t=f+d+n+n+2;
	for(int i=1;i<=f;i++)
	{
		F[i]=++tot;
		add(s,F[i],1);
		add(F[i],s,0);
	}
	for(int i=1;i<=d;i++)
	{
		D[i]=++tot;
		add(D[i],t,1);
		add(t,D[i],0);
	}
	for(int i=1;i<=n;i++)
	{
		in[i]=++tot;
		out[i]=++tot;
		add(in[i],out[i],1);
		add(out[i],in[i],0);
	}
	for(int i=1;i<=n;i++)
	{
		int numa,numb;
		cin>>numa>>numb;
		for(int j=1;j<=numa;j++)
		{
			int x;cin>>x;
			add(F[x],in[i],1);
			add(in[i],F[x],0);
		}
		for(int j=1;j<=numb;j++)
		{
			int x;cin>>x;
			add(out[i],D[x],1);
			add(D[x],out[i],0);
		}
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