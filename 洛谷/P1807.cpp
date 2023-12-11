#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis>dis;	
	}
};
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
ll dis[maxn];
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	for(int i=1;i<=n;i++)
		dis[i]=-1e6;
	bitset<maxn>vis;
	priority_queue<node>q;
	q.push({1,0});
	dis[1]=0;
	while(!q.empty()){
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dis[y]<dis[x]+edge[i].w){
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
	if(dis[n]==-1e6)cout<<-1<<endl;
	else cout<<dis[n]<<endl;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	dij();
}