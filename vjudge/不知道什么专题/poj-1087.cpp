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
#include<map>
using namespace std;
#define endl "\n"
#define int long long
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dep[maxn];
int n,m,k,s,t,tot;
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
	memset(dep,0,sizeof(dep));
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
		int w=edge[i].w;
		int y=edge[i].to;
		if(w&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(flow==out)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
map<string,int>in,out,mp;
void solve()
{
	s=1,t=2,tot=2;
	cnt=1;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string x;
		cin>>x;
		mp[x]=++tot;
		in[x]=++tot;
		out[x]=++tot;
		add(s,mp[x],1);
		add(mp[x],s,0);

		add(in[x],out[x],INF);
		add(out[x],in[x],0);

		add(mp[x],in[x],INF);
		add(in[x],mp[x],0);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string x,y;
		cin>>x>>y;
		mp[x]=++tot;

		if(!out[y])
		{
			in[y]=++tot;
			out[y]=++tot;
			add(in[y],out[y],INF);
			add(out[y],in[y],0);
		}

		add(out[y],mp[x],INF);
		add(mp[x],out[y],0);

		add(mp[x],t,1);
		add(t,mp[x],0);
	}
	cin>>k;
	for(int i=1;i<=k;i++)
	{
		string x,y;
		cin>>x>>y;

		if(!in[x])
		{
			in[x]=++tot;
			out[x]=++tot;
			add(in[x],out[x],INF);
			add(out[x],in[x],0);
		}
		if(!out[y])
		{
			in[y]=++tot;
			out[y]=++tot;
			add(in[y],out[y],INF);
			add(out[y],in[y],0);
		}

		add(out[y],in[x],INF);
		add(in[x],out[y],0);
	}
	cout<<m-DINIC(s,t)<<endl;
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