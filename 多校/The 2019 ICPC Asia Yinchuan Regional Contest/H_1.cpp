#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<pii>v[maxn];
vector<pii>G[maxn];
vector<int>F[maxn];
vector<int>bcc[maxn];
bool vis[maxn];
int dis[maxn];
int in[maxn];
int f[maxn];
int n,m1,m2,s;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void merge(int x,int y){
	int fa=find(x),fb=find(y);
	if(fa!=fb)f[fa]=fb;
}
void dfs(int x){
	if(vis[x])return ;
	vis[x]=1;
	for(auto [y,w]:v[x])
		dfs(y);
	for(auto [y,w]:G[x])
		dfs(y);
}
void dij(int _x)
{
	priority_queue<node>q;
	for(auto x:bcc[_x])
	{
		vis[x]=0;
		q.push({x,dis[x]});
	}
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
		{
			if(dis[y]>dis[x]+w)
			{
				dis[y]=dis[x]+w;
				q.push({y,dis[y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m1>>m2>>s;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=m1;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
		merge(x,y);
	}
	for(int i=1;i<=m2;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		G[x].push_back({y,w});
	}
	dfs(s);
	for(int x=1;x<=n;x++)
	{
		for(auto [y,w]:G[x])
		{
			if(!vis[x])continue;
			if(!vis[y])continue;
			in[find(y)]++;
			F[find(x)].push_back(find(y));
		}
		bcc[find(x)].push_back(x);
		dis[x]=INF;
	}
	queue<int>q;
	q.push(find(s));
	dis[s]=0;
	while(!q.empty())
	{
		int _x=q.front();q.pop();
		dij(_x);
		for(auto x:bcc[_x])
			for(auto [y,w]:G[x])
				dis[y]=min(dis[y],dis[x]+w);
		for(auto y:F[_x])
		{
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==INF)cout<<"NO PATH"<<endl;
		else cout<<dis[i]<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}