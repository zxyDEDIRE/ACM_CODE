/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
#include<queue>
#include<bitset>
using namespace std;
#define int long long
#define endl "\n"
const int maxn=1e6;
struct N{
	int x,dis;
	bool operator<(const N&a)const{
		return a.dis<dis;
	}
};
struct node{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	priority_queue<N>q;
	bitset<maxn>vis;
	for(int i=1;i<=n;i++)
		dis[i]=0x3f3f3f3f;
	dis[1]=0;
	N xx;
	xx.x=1;xx.dis=0;
	q.push(xx);
	while(!q.empty())
	{
		N now;
		now=q.top();q.pop();
		int x=now.x;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				xx.x=y;
				xx.dis=dis[y];
				q.push(xx);
			}
		}
	}
	cout<<dis[n]<<endl;
}
void solve()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij();
}
signed main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}