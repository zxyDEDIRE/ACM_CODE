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
const int maxn=1e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
bitset<maxn>vis;
int h[maxn];
int n,m,s,t;
int a,b,c;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	s=1,t=n;
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[s]=0;
	vis.reset();
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}

}
void solve()
{
	cin>>n>>m>>a>>b>>c;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(h[x]==h[y])
		{
			add(x,y,a);
			add(y,x,a);
			add(x,y,min(b,a+c));
			add(y,x,min(b,a+c));
		}
		else
		{
			add(x,y,a);
			add(y,x,a);
			add(x,y,min(b,a+c));
			add(y,x,min(b,a+c));
		}
	}
	dij();
	cout<<dis[n]<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}