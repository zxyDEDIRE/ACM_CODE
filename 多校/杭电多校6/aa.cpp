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
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
bitset<maxn>vis;
int in[maxn];
int h[maxn];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa()
{
	for(int i=1;i<=n;i++)dis[i]=INF;
	queue<int>q;
	dis[1]=0;
	vis[1]=1;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(in[x]>=n/2)
		{
			q.push(x);
			vis[x]=1;
			continue;
		}
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				in[y]=in[x]+1;
				if(in[y]>=n)return false;
				if(!vis[y])
				{
					q.push(y);
					vis[y]=1;
				}
			}
		}
	}
	return 1;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(h[x]>h[y])
		{
			add(x,y,-(h[x]-h[y]));
			add(y,x,2*h[x]-2*h[y]);
		}
		else
		{
			add(x,y,-2*(h[x]-h[y]));
			add(y,x,(h[x]-h[y]));
		}
	}
	spfa();
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=min(ma,dis[i]);
	cout<<-ma<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}