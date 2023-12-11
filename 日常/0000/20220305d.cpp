#include<bits/stdc++.h>
#define int long long
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=100;
bool vis[maxn][maxn];
char mp[maxn][maxn];
int n,m,sx,sy,res;
struct node{
	int x,y,ans;
	node(int a,int b,int c){x=a,y=b,ans=c;}
};
void bfs()
{
	queue<node>q;
	q.push(node(sx,sy,1));
	while(!q.empty())
	{
		node now=q.front();q.pop();
		int x=now.x;
		int y=now.y;
		res=max(res,now.ans);
		if(vis[x][y])continue;
		vis[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(mp[xx][yy]=='#')continue;
			if(xx<1||yy<1||xx>n||yy>m){res=max(res,now.ans);continue;}
			q.push(node(xx,yy,now.ans+1));
		}
	}
}
signed main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='@')sx=i,sy=j;
		}
	bfs();
	cout<<res<<endl;
}
/*
11 9
.#.........
.#.#######.
.#.#.....#.
.#.#.###.#.
.#.#..@#.#.
.#.#####.#.
.#.......#.
.#########.
...........

14 13
.##..#...#..#.
##..##....##.#
.#....##..##..
.#......####..
####..#....#..
#..#.#....##.#
#..#.###..#...
...#.#...#.#..
...#......#...
.#.#.###...#..
#..##...#.#...
...#.##...#...
.#.@..#....###

*/
