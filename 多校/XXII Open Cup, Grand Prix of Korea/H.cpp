/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+1000;
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
int ans[maxn];
int a[maxn];
int n,m,t;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int T)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	vis.reset();
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
		if(a[i]&(1<<T)){
			dis[i]=0;
			q.push({i,0});
		}
	while(!q.empty())
	{
		auto [x,D]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		D%=m;if(!D&&dis[x])D=m;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=w<D?w-D+m:w-D;
			if(dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				q.push({y,dis[y]});
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(dis[i]<=t)
			ans[i]+=(1<<T);
}
void solve()
{
	cin>>n>>m>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(y,x,i);
	}
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<8;i++)
		dij(i);
	for(int i=1;i<=n;i++)
		cout<<ans[i]<<" ";
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
7 4 1
1 2
2 1
1 2
2 1
8 4 2 4 8 0 3
12 12 2 4 8 0 3
12 4 2 4 8 0 3
*/