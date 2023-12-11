/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
const int N=50;
struct node{int x,y,z,step;};
bool vis[N][N][2];
int dis[N][N][2];
char mp[N][N][2];
int sx,sy,sz;
int n,m,t;
void bfs(int sx,int sy,int sz)
{
	queue<node>q;
	q.push({sx,sy,sz,0});
	vis[sx][sy][sz]=1;
	while(!q.empty())
	{
		node now=q.front();q.pop();
		int x=now.x;
		int y=now.y;
		int z=now.z;
		int step=now.step;
		if(mp[x][y][z]=='P'){
			if(step<=t)cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			int zz=z;
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy][zz]=='#'&&mp[xx][yy][zz^1]=='#')continue;
			if(mp[xx][yy][zz]=='#')zz^=1;
			if(mp[xx][yy][zz]=='*')continue;
			if(vis[xx][yy][zz])continue;
			vis[xx][yy][zz]=1;
			q.push({xx,yy,zz,step+1});
		}
	}
	cout<<"NO"<<endl;
	// for(int k=0;k<2;k++)
	// {
	// 	for(int i=1;i<=n;i++){
	// 		for(int j=1;j<=m;j++)
	// 			cout<<dis[i][j][k]<<" ";
	// 		cout<<endl;
	// 	}
	// 	cout<<endl;
	// }
}
void solve()
{
	cin>>n>>m>>t;
	memset(vis,0,sizeof(vis));
	for(int k=0;k<2;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				cin>>mp[i][j][k];
				if(mp[i][j][k]=='S'){
					sx=i,sy=j,sz=k;
				}
			}
	bfs(sx,sy,sz);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
5 5 14
S*#*.
.#...
.....
****.
...#.
..*.P
#.*..
***..
...*.
*.#..
5 5 13
S*#*.
##...
.....
****.
...#.
..*.P
..*..
***..
...*.
*.#..
5 5 10
S*#*.
.#...
....#
****.
...#.
..*.P
#.*.*
***..
...*.
*.#..
1 2 10
SP
*.
1 3 2
S#P
..#
3 3 11
S..
*#.
#..
...
.#.
.*P
*/