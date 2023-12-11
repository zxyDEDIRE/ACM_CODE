#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int INF=1e18;
const int maxn=5e6;
const int N=666;
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
bitset<maxn>vis;
int dis[maxn];
string mp[N];
int in[N][N];
int n,m,T,tot;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	vis.reset();
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>T;
	for(int i=1;i<=n;i++)
		for(int j=0;j<T;j++)
			in[i][j]=++tot;
	for(int i=1;i<=n;i++)
		cin>>mp[i];	
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<T;j++)
		{
			//add(in[i][j],in[i][(j+1)%T],1);
			add(in[i][(j+1)%T],in[i][j],1);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		for(int j=0;j<T;j++)
		{
			//x->y
			if(mp[x][j]=='1')
			{
				// add(in[x][j],in[y][(j+w)%T],w);
				add(in[y][(j+w)%T],in[x][j],w);
			}
			//y->x
			if(mp[y][j]=='1')
			{
				// add(in[y][j],in[x][(j+w)%T],w);
				add(in[x][(j+w)%T],in[y][j],w);
			}
		}
	}
	int t=++tot;
	for(int i=0;i<T;i++)
	{
		add(t,in[n][i],0);
	}
	dij(t);
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=0;j<T;j++)
	// 		cout<<dis[in[i][j]]<<" ";
	// 	cout<<endl;
	// }
	for(int i=0;i<T;i++)
		cout<<dis[in[1][i]]<<" ";
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
}
/*
4 4 5
01234
11111
00001
01000
00000
1 2 1
2 4 1
1 3 1
3 4 1

*/