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
const int INF=1e18+7;
const int maxn=1e6+10;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bool vis[102][maxn];
int dis[102][maxn];
int n,m,k;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void spfa(int s)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dis[i][j]=INF;
	queue<pii>q;
	q.push({s,0});
	dis[s][0]=0;
	vis[s][0]=1;
	while(!q.empty())
	{
		auto [x,t]=q.front();q.pop();
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y][t]>dis[x][t]+w)
			{
				dis[y][t]=dis[x][t]+w;
				if(!vis[y][t])
					q.push({y,t});
			}
			if(t+1<=k&&dis[y][t+1]>dis[x][t]-w)
			{
				dis[y][t+1]=dis[x][t]-w;
				if(!vis[y][t+1])
					q.push({y,t+1});
			}
		}
	}
}
void Floyd()
{
	
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
	}
	spfa(1);
	int ma=dis[n][0];
	for(int i=0;i<=k;i++)
		ma=min(ma,dis[n][i]);
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	// Floyd();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}