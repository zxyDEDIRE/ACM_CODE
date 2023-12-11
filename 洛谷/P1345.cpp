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
const int INF=1e9+7;
const int maxn=1e6;
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
vector<int>v[maxn];
bitset<maxn>vis;
int out[maxn];
int in[maxn];
int a,b;
void dfs(int x)
{
	for(auto y:v[x])
	{
		if(vis[y])continue;
		vis[y]=1;
		add(out[x],in[y],INF);
		add(in[y],out[x],INF);
		dfs(y);
	}
}
void solve()
{
	cin>>n>>m>>a>>b;
	init();
	for(int i=1;i<=n;i++)
	{
		in[i]=++tot;
		out[i]=++tot;
		add(in[i],out[i],1);
		add(out[i],in[i],0);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(out[x],in[y],INF);
		add(in[y],out[x],0);

		add(out[y],in[x],INF);
		add(in[x],out[y],0);
	}
	s=out[a];
	t=in[b];
	cout<<DINIC(s,t)<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1345_1.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}