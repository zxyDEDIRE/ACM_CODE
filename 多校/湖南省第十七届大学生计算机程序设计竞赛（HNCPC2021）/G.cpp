#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int N=1111;
bool vis[111][111][1111];
char mp[N][N];
int id[N][N];
int sx,sy;
int n,m,ans;
void dfs(int x,int y,int fl,int op)
{
	if(vis[x][y][fl])return ;
//	cout<<x<<" "<<y<<" "<<__builtin_popcount(fl)<<" "<<__builtin_popcount(op)<<endl;
	vis[x][y][fl]=1;
	if(x==sx&&y==sy&&op!=0)
	{
		ans=max(ans,__builtin_popcount(op));
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]!='@')continue;
		int ID = id[xx][yy];
		if((op&(1<<ID)))continue;
		op|=(1<<ID);
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]=='#')continue;
		int ID=0;
		if(mp[xx][yy]=='X')ID=(1<<id[xx][yy]);
		if(fl&ID)continue;
		dfs(xx,yy,fl|ID,op);
	}
}
void solve()
{
	int x_tot=0;
	int y_tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='X'){
				id[i][j]=x_tot++;
			}
			else if(mp[i][j]=='@'){
				id[i][j]=y_tot++;
			}
			else id[i][j]=0;
			for(int k1=0;k1<=1024;k1++)
					vis[i][j][k1]=0;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(mp[i][1]=='.')sx=i,sy=1;
		if(mp[i][m]=='.')sx=i,sy=m; 
	}
	for(int i=1;i<=m;i++)
	{
		if(mp[1][i]=='.')sx=1,sy=i;
		if(mp[n][i]=='.')sx=n,sy=i;
	}
	ans=0;
	dfs(sx,sy,0,0);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin >> n >> m)
//	cin>>n>>m;
		solve(); 
	return 0;
}
