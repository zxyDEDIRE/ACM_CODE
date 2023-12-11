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
	int id,xt,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bool vis[maxn][11];
int dis[maxn][11];
int n,m,k,s,t;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s,int y)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dis[i][j]=INF,vis[i][j]=0;
	priority_queue<node>q;
	q.push({s,0,0});
	dis[s][0]=0;
	while(!q.empty())
	{
		auto [x,xt,DIS]=q.top();q.pop();
		if(vis[x][xt])continue;
		vis[x][xt]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(xt<k)
			{
				if(dis[y][xt+1]>dis[x][xt])
				{
					dis[y][xt+1]=dis[x][xt];
					q.push({y,xt+1,dis[y][xt+1]});
				}
			}
			if(dis[y][xt]>dis[x][xt]+w)
			{
				dis[y][xt]=dis[x][xt]+w;
				q.push({y,xt,dis[y][xt]});
			}
		}
	}
	int mi=dis[t][0];
	for(int i=0;i<=k;i++)
		mi=min(mi,dis[t][i]);
	cout<<mi<<endl;
	cout<<dis[t][k]<<endl;
}
void solve()
{
	cin>>n>>m>>k>>s>>t;
	s++,t++;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		x++,y++;
		add(x,y,w);
		add(y,x,w);
	}
	dij(s,t);
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
5 6 100
0 4
0 1 5
1 2 5
2 3 5
3 4 5
2 3 3
0 2 100
(ax+by-c)

*/