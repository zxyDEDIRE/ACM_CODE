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
const int maxn=1e6+100;
struct node{
	int id,a,b,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn][2][2];
bool vis[maxn][2][2];
int n,m;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i][0][0]=dis[i][1][0]=dis[i][0][1]=dis[i][1][1]=INF;
	priority_queue<node>q;
	q.push({s,0,0,0});
	dis[s][0][0]=0;
	while(!q.empty())
	{
		auto [x,a,b,IDS]=q.top();q.pop();
		if(vis[x][a][b])continue;
		vis[x][a][b]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y][a][b]>dis[x][a][b]+w)
			{
				dis[y][a][b]=dis[x][a][b]+w;
				q.push({y,a,b,dis[y][a][b]});
			}
			if(a==0&&dis[y][1][b]>dis[x][0][b]+w+w){
				dis[y][1][b]=dis[x][0][b]+w+w;
				q.push({y,1,b,dis[y][1][b]});
			}
			if(b==0&&dis[y][a][1]>dis[x][a][0]){
				dis[y][a][1]=dis[x][a][0];
				q.push({y,a,1,dis[y][a][1]});
			}
			if(a==0&&b==0&&dis[y][1][1]>dis[x][0][0]+w){
				dis[y][1][1]=dis[x][0][0]+w;
				q.push({y,1,1,dis[y][1][1]});
			}
		}
	}
	for(int i=2;i<=n;i++)
		cout<<dis[i][1][1]<<" ";
	cout<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dij(1);
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