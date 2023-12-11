/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int dis[maxn];
int f[maxn];
int n,m,b;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool dij(int mid)
{
	for(int i=1;i<=n;i++)dis[i]=INF;
	vis.reset();
	priority_queue<node>q;
	if(f[1]<=mid)
		q.push({1,0});
	dis[1]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(f[y]>mid)continue;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
	return dis[n]<=b;
}
void solve()
{
	cin>>n>>m>>b;
	int mi=INF,ma=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i];
		ma=max(ma,f[i]);
		mi=min(mi,f[i]);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	int l=max(mi-1000,0ll),r=ma+1000,ans=INF;
	while(l<r-1)
	{
		int mid=(l+r)/2;
		if(dij(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(ans==INF)cout<<"AFK"<<endl;
	else if(dij(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1462_8.in","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	 // fclose(stdin);
	 // fclose(stdout);
	return 0;
}