#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
const int INF=1e9+7;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
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
int out[maxn];
int in[maxn];
int sum=0;
void solve()
{
	cin>>n>>m;
	init();sum=0;
	for(int i=1;i<=n;i++)
		in[i]=++tot;
	for(int i=1;i<=500;i++)
		out[i]=++tot;
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
	{
		int l,r,w;
		cin>>w>>l>>r;
		add(s,in[i],w);
		add(in[i],s,0);
		sum+=w;
		for(int j=l;j<=r;j++)
		{
			add(in[i],out[j],1);
			add(out[j],in[i],0);
		}
	}
	for(int i=1;i<=500;i++)
	{
		add(out[i],t,m);
		add(t,out[i],0);
	}
	int ans=DINIC(s,t);
	// cout<<endl;
	// cout<<ans<<" "<<sum<<endl;
	if(ans==sum)cout<<"Yes\n\n";
	else cout<<"No\n\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	for(int i=1;i<=__;i++)
	{
		cout<<"Case "<<i<<": ";
		solve();
	}
		
}