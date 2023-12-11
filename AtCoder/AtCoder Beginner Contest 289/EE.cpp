/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=2e3+10;
struct node{
	int id_x,id_y,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[N];
bool vis[N][N];
int dis[N][N];
int col[maxn];
int n,m;
void dij(int sx,int sy)
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF,vis[i][j]=0;
	dis[sx][sy]=0;
	priority_queue<node>q;
	q.push({sx,sy,0});
	while(!q.empty())
	{
		auto [x,y,DIS]=q.top();q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		for(auto xx:v[x])
		{
			for(auto yy:v[y])
			{
				if(col[xx]==col[yy])continue;
				if(dis[xx][yy]>dis[x][y]+1)
				{
					dis[xx][yy]=dis[x][y]+1;
					q.push({xx,yy,dis[xx][yy]});
				}
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>col[i];
		v[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dij(1,n);
	if(dis[n][1]==INF)cout<<-1<<endl;
	else cout<<dis[n][1]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}