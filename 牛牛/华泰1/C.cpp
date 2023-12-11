#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int INF=1e9+7;
const int N=100;
struct node{
	int x,y,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
bool vis[N][N];
char mp[N][N];
int dis[N][N][N][N];
int cnt[N][N][N][N];
// vector<int>a[N][N][N][N];
string s;
int n,m;
void dij(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dis[sx][sy][i][j]=INF;
	dis[sx][sy][sx][sy]=0;
	priority_queue<node>q;
	q.push({sx,sy,0});
	cnt[sx][sy][sx][sy]=1;
	while(!q.empty())
	{
		auto [x,y,DIS]=q.top();q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]=='*')continue;
			if(dis[sx][sy][xx][yy]>dis[sx][sy][x][y]+1)
			{
				dis[sx][sy][xx][yy]=dis[sx][sy][x][y]+1;
				q.push({xx,yy,dis[sx][sy][xx][yy]});
				cnt[sx][sy][xx][yy]=cnt[sx][sy][x][y];
			}
			else if(dis[sx][sy][xx][yy]==dis[sx][sy][x][y]+1)
				cnt[sx][sy][xx][yy]+=cnt[sx][sy][x][y];
		}
	}
}
void solve()
{
	cin>>n>>m;
	int sx,sy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='R')
				sx=i,sy=j;
		}
	cin>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dij(i,j);

	int x=sx,y=sy;
	int _x=sx,_y=sy;
	int num=0;
	int len=0;
	for(auto i:s)
	{
		if(i=='W')
			sx--;
		else if(i=='S')
			sx++;
		else if(i=='A')
			sy--;
		else if(i=='D')
			sy++;
		if(cnt[x][y][sx][sy]!=1)
		{
			num++;
			x=_x;
			y=_y;
			len=0;
		}
		else if(dis[_x][_y][sx][sy]+len!=dis[x][y][sx][sy])
		{
			num++;
			x=_x;
			y=_y;
			len=0;
		}
		len+=dis[_x][_y][sx][sy];
		_x=sx;
		_y=sy;
	}
	cout<<num+1<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
/*
.2*
43R
...

AWSA
*/