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
const int N=444;
struct Node{
	int id,dis;
	bool operator<(const Node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bitset<N>vis,ok;
int s[maxn],t[maxn];
int dis[N][N];
int n,m;
void dij(int s)
{
	for(int i=1;i<=400;i++)
		dis[s][i]=INF;
	priority_queue<Node>q;
	vis.reset();
	q.push({s,0});
	dis[s][s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[s][y]>dis[s][x]+w)
			{
				dis[s][y]=dis[s][x]+w;
				q.push({y,dis[s][y]});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=0;i<n;i++)
		cin>>t[i];
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		ok[x]=ok[y]=1;
		add(x,y,w);
	}
	for(int i=1;i<=400;i++)
		if(ok[i])
			dij(i);

	ll ans=INF;
	for(int i=0;i<n;i++){
		ll now=0;
		for(int j=0;j<n;j++){
			int x=s[j];
			int y=t[(i+j)%n];
			if(x==y)continue;
			int w=min(dis[x][y],dis[y][x]);
			if(w==INF){
				now=INF;
				break;
			}
			now+=w;
		}
		ans=min(ans,now);
	}
	cout<<(ans==INF?-1:ans)<<"\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}