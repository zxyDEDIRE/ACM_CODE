#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<utility>
using std::min;
using std::vector;
using std::queue;
using std::priority_queue;
using namespace std;
const int INF=0x3f3f3f3f;
const int N=2e4+5,M=2e5+5,inf=0x3f3f3f3f;
int n,s,t,tot;
int p[N];
int v[M<<1],w[M<<1],first[N],net[M<<1];
int h[N],e[N],gap[N<<1],inq[N];//节点高度是可以到达2n-1的
struct cmp
{
	inline bool operator()(int a,int b) const
	{
		return h[a]<h[b];//因为在优先队列中的节点高度不会改变，所以可以直接比较
	}
};
queue<int> Q;
priority_queue<int,vector<int>,cmp> pQ;
void init()
{
	tot=0;
	memset(first,0,sizeof(int)*(t+10));
}
inline void add(int from,int to,int flow)
{
	tot+=2;
	v[tot+1]=from;v[tot]=to;w[tot]=flow;w[tot+1]=0;
	net[tot]=first[from];first[from]=tot;
	net[tot+1]=first[to];first[to]=tot+1;
	return;
}
inline bool bfs()
{
	int now;
	int go;
	memset(h+1,0x3f,sizeof(int)*t);
	h[t]=0;Q.push(t);
	while(!Q.empty())
	{
		now=Q.front();Q.pop();
		for(go=first[now];go;go=net[go])
			if(w[go^1]&&h[v[go]]>h[now]+1)
				h[v[go]]=h[now]+1,Q.push(v[go]);
	}
	return h[s]!=inf;
}
inline void push(int now)//推送
{
	int d;
	int go;
	for(go=first[now];go;go=net[go])
		if(w[go]&&h[v[go]]+1==h[now])
		{
			d=min(e[now],w[go]);
			w[go]-=d;w[go^1]+=d;e[now]-=d;e[v[go]]+=d;
			if(v[go]!=s&&v[go]!=t&&!inq[v[go]])
				pQ.push(v[go]),inq[v[go]]=1;
			if(!e[now])//已经推送完毕可以直接退出
				break;
		}
	return;
}
inline void relabel(int now)//重贴标签
{
	int go;
	h[now]=inf;
	for(go=first[now];go;go=net[go])
		if(w[go]&&h[v[go]]+1<h[now])
			h[now]=h[v[go]]+1;
	return;
}
inline int hlpp()
{
	int now,d;
	int i,go;
	if(!bfs())//s和t不连通
		return 0;
	h[s]=t;
	memset(gap,0,sizeof(int)*(t<<1));
	for(i=1;i<=t;i++)
		if(h[i]<inf)
			++gap[h[i]];
	for(go=first[s];go;go=net[go])
		if(d=w[go])
		{
			w[go]-=d;w[go^1]+=d;e[s]-=d;e[v[go]]+=d;
			if(v[go]!=s&&v[go]!=t&&!inq[v[go]])
				pQ.push(v[go]),inq[v[go]]=1;
		}
	while(!pQ.empty())
	{
		inq[now=pQ.top()]=0;pQ.pop();push(now);
		if(e[now])
		{
			if(!--gap[h[now]])//gap优化，因为当前节点是最高的所以修改的节点一定不在优先队列中，不必担心修改对优先队列会造成影响
				for(i=1;i<=t;i++)
					if(i!=s&&i!=t&&h[i]>h[now]&&h[i]<t+1)
						h[i]=t+1;
			relabel(now);++gap[h[now]];
			pQ.push(now);inq[now]=1;
		}
	}
	return e[t];
}
int m;
void solve()
{
	int n,m1,m2;
	cin>>n>>m1>>m2;
	for(int i=1;i<=n;i++)
		p[i]=0;
	vector<pair<int,int>>V;
	for(int i=1;i<=m1;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		if(w==1)p[x]++;
		else p[y]++;
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y;
		cin>>x>>y;
		if(x==1||y==1)p[1]++;
		else V.push_back(pair<int,int>(x,y));
	}
	int sum=0;
	s=n+V.size()+1;
	t=s+1;
	init();
	for(int i=0;i<V.size();i++)
	{
		sum++;
		int x=V[i].first;
		int y=V[i].second;
		int in=i+n+1;
		add(s,in,1);
		add(in,s,0);

		add(in,x,INF);
		add(x,in,0);


		add(in,y,INF);
		add(y,in,0);
	}
	for(int i=2;i<=n;i++)
	{
		sum+=p[i];
		add(s,i,p[i]);
		add(i,s,0);

		add(i,t,p[1]);
		add(t,i,0);
	}
	int res=hlpp();
	//cout<<sum<<" "<<res<<endl;
	if(res<sum)cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}