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
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis,w;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bool vis[maxn][3];
int dis[maxn][3];
bool S[maxn];
int n,m,k;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij()
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=1;j++)
			dis[i][j]=INF,vis[i][j]=0;
	priority_queue<node>q;
	q.push({1,0,0});
	dis[1][0]=0;
	while(!q.empty())
	{
		auto [x,DIS,W]=q.top();q.pop();
		if(vis[x][W])continue;
		vis[x][W]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(W==0&&w==1||(S[x]&&w==1))
			{
				if(dis[y][0]>dis[x][W]+1)
				{
					dis[y][0]=dis[x][W]+1;
					q.push({y,dis[y][0],0});
				}
			}
			if(W==1&&w==0||(S[x]&&w==0))
			{
				if(dis[y][1]>dis[x][W]+1)
				{
					dis[y][1]=dis[x][W]+1;
					q.push({y,dis[y][1],1});
				}
			}
		}
	}
	int ans=min(dis[n][0],dis[n][1]);
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	for(int i=1;i<=k;i++)
	{
		int x;
		cin>>x;
		S[x]=1;
	}
	dij();
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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


*/
