#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis>dis;	}
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
void spfa()
{
	bitset<maxn>vis;
	for(int i=1;i<=n;i++)
		dis[i]=-INF;
	queue<int>q;
	q.push(1);
	vis[1]=1;
	dis[1]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			dis[y]=max(dis[y],dis[x]+edge[i].w);
			if(!vis[y])q.push(y),vis[y]=1;
		}
	}
	if(dis[n]==-INF)cout<<-1;
	else cout<<dis[n];
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	spfa();
}