#include<iostream>
#include<algorithm>
#include<bitset>
#include<queue>
using namespace std;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(){}
	node(int a,int b):id(a),dis(b){}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int n,m,s,t;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	vis.reset();dis[s]=0;
	q.push(node(s,0));
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push(node(y,dis[y]));
			}
		}
	}
}
void solve()
{
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x;cin>>x;int fl=(j!=1);
			add(i,x,fl);
		}
	}
	dij(s);
	cout<<(dis[t]==INF?-1:dis[t])<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}