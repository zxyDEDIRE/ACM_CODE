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
const int N=111;
char mp[N][N];
int ans[N];
int n,m;
void doit(int x,int y)
{
	int len=1;
	while(1)
	{
		int flag=1;
		for(int i=4;i<8;i++)
		{
			int xx=x+dx[i]*len;
			int yy=y+dy[i]*len;
			if(mp[xx][yy]!='#')flag=0;
		}
		if(!flag)break;
		else len++;
	}
	len--;
	ans[len]++;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='#')
				doit(i,j);
	}
	for(int i=1;i<=min(n,m);i++)
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
15 20
.....#.............#
......#...........#.
.......#.........#..
........#.......#...
#.....#..#.....#....
.#...#....#...#.....
..#.#......#.#......
...#........#.......
..#.#......#.#......
.#...#....#...#.....
#.....#..#.....#....
........#.......#...
.......#.........#..
......#...........#.
.....#.............#
0 0 1 0 0 0 1 0 0 0 0 0 0 0 0
*/