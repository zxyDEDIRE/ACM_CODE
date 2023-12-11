#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int mp[53][53];
int vis[53][53];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
struct poi
{
	int x,y,su;
};
queue<poi>q;
int OK(int x,int y)
{
	return x>=1&&x<=n&&y>=1&&y<=m;
}
int dfs(int x,int y)
{
	int sum=0;
	for(int i=0;i<4;i++){
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		if(OK(xx,yy)){
			if(vis[xx][yy]==1)continue;
			if(mp[xx][yy]!=mp[x][y])sum++;
			else{
				vis[xx][yy]=1;
				sum+=dfs(xx,yy);
			}
		}
	}
	return sum;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	int sx,sy,maxx=-1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j])continue;
			int t=dfs(i,j);
			if(t>maxx)sx=i,sy=j,maxx=t;
		}
	}
	int ans=0;
	poi a,b;
	a.x=sx,a.y=sy,a.su=0;
	q.push(su);
	
	
}
