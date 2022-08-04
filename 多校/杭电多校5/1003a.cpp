/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const ll INF=1e18;
const int maxn=2e6+10;
struct Edge{
	int to,next;ll w;
}edge[maxn];
struct node{
	int id;
	ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
ll dis[maxn];
int dep[maxn],depmax;
int n,k,p,s,t;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
}
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
	depmax=max(depmax,deep);
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
		if(x==t)return ;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				if(vis[y])continue;
				node is;
				is.id=y;
				is.dis=dis[y];
				q.push(is);
			}
		}
	}
}
void solve()
{
	read(n);
	depmax=0;
	cnt=0;
	for(int i=0;i<=n*2;i++)
	{
		dis[i]=INF;
		v[i].clear();
		head[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		read(x);
		read(y);
		read(w);
		add(x,y,w);
		add(y,x,w);
	}
	read(k);
	read(p);
	read(s);
	read(t);
	dfs(1,1,1);
	for(int i=1;i<=depmax;i++)
	{
		for(auto x:v[i])
			add(x,n+i,p);
		if(i+k<=depmax)
		{
			for(auto x:v[i+k])
				add(n+i,x,0);
		}
	}
	dij(s);
	printf("%lld\n",dis[t]);
}
signed main()
{	
	int __;
	read(__);
	while(__--)
		solve();
	return 0;
}