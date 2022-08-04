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
const int INF=0x3f3f3f3f;
const int maxn=1e6+7;
struct Edge{
	int to,next;ll w;
}edge[maxn];
struct node{
	int id;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
ll dis[maxn];
ll mi[maxn];
int dep[maxn];
int n,k,Q,s,t;
void add(int from,int to,ll w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int x,int f,int deep)
{
	dep[x]=deep;
	v[deep].push_back(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f)continue;
		dfs(y,x,deep+1);
	}
}
void dij(int s)
{
	vis.reset();
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	vis[s]=1;
	priority_queue<node>q;
	node it;
	it.id=s;
	it.dis=0;
	q.push(it);
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
		ll mi=INF;

		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				mi=min(mi,edge[i].w);
				dis[y]=dis[x]+edge[i].w;
				if(vis[y])continue;
				node is;
				is.id=y;
				is.dis=dis[y];
				q.push(is);
			}
		}
		if(mi>=Q)
		{
			for(auto y:v[dep[x]+k])
			{
				if(dis[y]>dis[x]+Q)
				{
					dis[y]=dis[x]+Q;
					if(vis[y])continue;
					node is;
					is.id=y;
					is.dis=dis[y];
					q.push(is);
				}
			}
		}
	}
	cout<<dis[t]<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		head[i]=0;
		mi[i]=INF;
	}
	for(int i=1;i<n;i++)
	{
		int x,y;ll w;
		cin>>x>>y>>w;
		add(x,y,w);
		mi[x]=min(mi[x],w);
		add(y,x,w);
		mi[y]=min(mi[y],w);
	}
	cin>>k>>Q>>s>>t;
	dfs(1,1,1);
	dij(s);
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
