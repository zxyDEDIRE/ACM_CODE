#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=1e9;
const int maxn=1e5;
struct Edge{int to,next,w;}edge[maxn];
struct node{
	int id,dis;
	ool operator<(const node&a)const{
		return a.dis<dis;
	}
};
int head[maxn],cnt;
int dis[maxn];
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
	for(int i=0;i<=n;i++)h[i]=INF;
	vector<int>in(n+10);
	bitset<maxn>vis;
	queue<int>q;
	q.push(0);
	vis[0]=1;
	h[0]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		vis[x]=0;
		in[x]++;
		if(in[x]>n)return 0;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(h[y]>h[x]+edge[i].w){
				h[y]=h[x]+edge[i].w;
				if(!vis[y]){
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
	return 1;
}
void dij(int s){
	for(int i=1;i<=n;i++)dis[i]=INF;
	bitset<maxn>vis;
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty()){
		auto [x,now]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w){
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	}
	for(int i=1;i<=n;i++)
		add(0,i,0);
	if(!spfa()){
		cout<<-1<<endl;
		return 0;
	}
	for(int u=1;u<=n;u++){
		for(int i=head[u];i;i=edge[i].next){
			edge[i].w+=h[u]-h[edge[i].to];
		}
	}
	for(int i=1;i<=n;i++){
		dij(i);
		ll ans=0;
		for(int j=1;j<=n;j++)
			if(dis[j]==INF)ans+=j*INF;
			else ans+=j*(dis[j]+h[j]-h[i]);
		cout<<ans<<endl;
	}
}
/*
5 7
1 2 4
1 4 10
2 3 7
4 5 3
4 2 -2
3 4 -3
5 3 4

138
1000000072
999999978
1000000026
1000000014

5 5
1 2 4
3 4 9
3 4 -3
4 5 3
5 3 -2
*/