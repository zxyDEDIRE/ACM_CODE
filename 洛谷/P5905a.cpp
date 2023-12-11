#include<bits/stdc++.h>
#define ll long long
#define INF 1e9
using namespace std;
const int maxn=1e5+5e4;
int n,m;
int cnt,head[maxn];
ll h[maxn],vis[maxn],t[maxn],dis[maxn];
struct Edge{int to,next,w;}edge[10005];
struct node{
	int id,w;
	//bool operator<(const node &a)const{return a.w<w;}
	bool operator<(const node& a)const{return w>a.w;}
	node(int x,int d){w=d,id=x;}
};
void add(int from,int to,int w){
	edge[++cnt].to=to;
	edge[cnt].w=w;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s){
	queue<int> q;
	memset(h,63,sizeof(h));
	h[s]=0,vis[s]=1;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		vis[u]=0;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(h[v]>h[u]+edge[i].w){
				h[v]=h[u]+edge[i].w;
				if(!vis[v]){
					vis[v]=1;
					q.push(v);
					t[v]++;
					if(t[v]==n+1)return false;
				}
			}
		}
	}
	return true;
}
void dij(int s){
	priority_queue<node>q;
	for(int i=1;i<=n;i++)dis[i]=INF;
	memset(vis,0,sizeof(vis));
	dis[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		int u=q.top().id;q.pop();
		if(vis[u])continue;
		vis[u]=1;
		for(int i=head[u];i;i=edge[i].next){
			int v=edge[i].to;
			if(dis[u]+edge[i].w<dis[v]){
				dis[v]=dis[u]+edge[i].w;
				if(!vis[v])q.push(node(v,dis[v]));
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;
		add(u,v,w);
	}
	for(int i=1;i<=n;i++)add(0,i,0);
	if(!spfa(0)){cout<<-1<<endl;return 0;}
	for(int u=1;u<=n;u++)
		for(int i=head[u];i;i=edge[i].next)
			edge[i].w+=h[u]-h[edge[i].to];
	for(int i=1;i<=n;i++){
		dij(i);
		long long ans=0;
		for(int j=1;j<=n;j++){
			if(dis[j]==INF)ans+=j*INF;
			else ans+=j*(dis[j]+h[j]-h[i]);
		}
		cout<<ans<<endl;
	}
}