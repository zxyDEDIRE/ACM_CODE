#include<iostream>
#include<algorithm>
#include<queue>
#include<bitset>
#include<stdio.h>
using namespace std;
const int maxn=1e6+10;
const int INF=2147483647;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node(){}
	node(int _id,int _dis):id(_id),dis(_dis){}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int n,m,ma;

inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s){
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	priority_queue<node>q;
	q.push(node(s,0));
	dis[s]=0;vis.reset();
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		ma=max(ma,now.dis);
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				q.push(node(y,dis[y]));
			}
		}
	}
}
void solve(){
	read(n);
	read(m);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		read(x);read(y);read(w);
		add(x,y,w);
	}
	dij(1);
	printf("%d\n",dis[n]);
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}