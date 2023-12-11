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
const int N=1e3;
bool vis[N][N];
int dis[N][N];
char mp[N][N];
int n,m,xs,ys,Q;
void bfs(int X,int Y)
{
	queue<pii>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dis[i][j]=INF;
	q.push({X,Y});
	dis[X][Y]=0;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<0||yy<0||xx>n||yy>m||mp[xx][yy]=='#')continue;
			if(dis[xx][yy]<=dis[x][y]+1)continue;
			dis[xx][yy]=dis[x][y]+1;
			q.push({xx,yy});
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 		printf("%13d",dis[i][j]);
	// 	cout<<endl;
	// }
}
int f(int x,int y)
{
	if(dis[x][y]==INF)return -1;
	int ans=0;
	while(1)
	{
		if(dis[x][y]<=ans)return ans;
		if(mp[x][y]=='L')
		{
			if(y-1<1||mp[x][y-1]=='#')return dis[x][y];
			y--;
		}
		else if(mp[x][y]=='R')
		{
			if(y+1>m||mp[x][y+1]=='#')return dis[x][y];
			y++;
		}
		else if(mp[x][y]=='U')
		{
			if(x-1<1||mp[x-1][y]=='#')return dis[x][y];
			x--;
		}
		else if(mp[x][y]=='D')
		{
			if(x+1>n||mp[x+1][y]=='#')return dis[x][y];
			x++;
		}
		else if(mp[x][y]=='.')
		{
			return dis[x][y];
		}
		ans++;
	}
}
void solve()
{
	cin>>n>>m>>xs>>ys>>Q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	bfs(xs+1,ys+1);
	while(Q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<f(x+1,y+1)<<endl;
	}
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
6 8 1 6 3
########
#UDLDLD#
#UDUDUD#
#UDUDUD#
#ULULUL#
########
1 1
2 6
4 1
*/