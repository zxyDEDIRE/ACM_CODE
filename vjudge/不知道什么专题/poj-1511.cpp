#include<algorithm>
#include<iostream>
#include<queue>
#include<bitset>
using namespace std;
const int INF=1e9+7;
const int maxn=1e6+10;
#define ll long long
struct node{
	int id;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(){}
	node(int _id,ll _dis):id(_id),dis(_dis){}
};
struct Edge{
	int to,next,w;
}ea[maxn],eb[maxn];
int ha[maxn],hb[maxn],cnta,cntb;
bitset<maxn>vis;
ll dis[maxn];
int n,m;
void adda(int from,int to,int w){
	ea[++cnta].w=w;
	ea[cnta].to=to;
	ea[cnta].next=ha[from];
	ha[from]=cnta;
}
void addb(int from,int to,int w){
	eb[++cntb].w=w;
	eb[cntb].to=to;
	eb[cntb].next=hb[from];
	hb[from]=cntb;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=cnta;i++)
		ha[i]=hb[i]=0;
	cnta=cntb=0;
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		adda(x,y,w);
		addb(y,x,w);
	}
	priority_queue<node>q;


	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[1]=0;vis.reset();
	q.push(node(1,0));
	while(!q.empty()){
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		ans+=now.dis;
		for(int i=ha[x];i;i=ea[i].next)
		{
			int y=ea[i].to;
			int w=ea[i].w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push(node(y,dis[y]));
			}
		}
	}

	for(int i=1;i<=n;i++)dis[i]=INF;
	dis[1]=0;vis.reset();
	q.push(node(1,0));
	while(!q.empty()){
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		ans+=now.dis;
		for(int i=hb[x];i;i=eb[i].next)
		{
			int y=eb[i].to;
			int w=eb[i].w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push(node(y,dis[y]));
			}
		}
	}

	cout<<ans<<"\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
