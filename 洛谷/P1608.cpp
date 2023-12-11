#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=5e6;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct E{int x,y,z;
	bool operator<(const E&a)const{
		if(a.x!=x)return a.x<x;
		if(a.y!=y)return a.y<y;
		return a.z<z;
	}
};
struct Edge{int to,next,w;}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
int ans[maxn];
int n,m;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
		dis[i]=INF,ans[i]=1;
	dis[1]=0;
	bitset<maxn>vis;
	q.push({1,0});
	while(!q.empty()){
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w){
				ans[y]=ans[x];
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
			else if(dis[y]==dis[x]+edge[i].w)ans[y]+=ans[x];
		}
	}
	if(dis[n]==INF){
		cout<<"No answer"<<endl;
		return ;
	}
	cout<<dis[n]<<" "<<ans[n]<<endl;
}
void solve()
{
	cin>>n>>m;
	map<E,bool>mp;
	for(int i=1;i<=m;i++){
		int x,y,z;
		cin>>x>>y>>z;
		if(!mp[{x,y,z}])add(x,y,z),mp[{x,y,z}]=1;
		
	}
	dij();
	
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;
//    cin>>__;
    __=1;
    while(__--)solve();
    return 0;
}
/*
5 5
1 2 1
2 3 1
3 4 1
4 5 1
1 4 3

*/