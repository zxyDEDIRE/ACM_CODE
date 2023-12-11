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
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int n,m;
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	dis[1]=0;
	priority_queue<node>q;
	q.push({1,0});
	while(!q.empty())
	{
		auto [x,X]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].to)
		{
			int w=edge[i].w;
			int c=edge[i].c;

		}
	}
}
/*
w+c/t
*/
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		add(a,b,c,d);
		add(b,a,c,d);
	}
	dij();
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}