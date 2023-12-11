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
int tt=0,an=0;
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
void dfs1(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	for(int i=0;i<4;i++){
		int xx=dx[i]+x;
		int yy=dy[i]+y;
		if(OK(xx,yy)){
			if(vis[xx][yy]==1)continue;
			if(mp[x][y]==mp[xx][yy]){
				vis[xx][yy]=1;
				dfs1(xx,yy);
			}
		}
	}
	mp[x][y]=2;
}
signed main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
		}
	}
	int sx,sy,maxx=-1,star;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(vis[i][j])continue;
			int t=dfs(i,j);
			if(t>maxx)sx=i,sy=j,maxx=t;
		}
	}
	memset(vis,0,sizeof(vis));
	dfs1(sx,sy);
	star=mp[sx][sy];
	//cout<<sx<<" "<<sy<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cout<<mp[i][j]<<" ";
		}
		puts("");
	}
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		bool f=0;
		for(int j=0;j<=m;j++)
		{
			if(mp[i][j]==2)
			{
				f=1;
				break;
			}
		}
		if(f)
		{
			int tmp=0,maxx=0;
			for(int j=2;j<=m;j++)
			{
				if(mp[i][j]!=mp[i][j-1])
					tmp++;
				if(mp[i][j]==2)
					break;
			}
			maxx=max(maxx,tmp);
			tmp=0;
			for(int j=m-1;j>0;j--)
			{
				if(mp[i][j]!=mp[i][j+1])
					tmp++;
				if(mp[i][j]==2)
					break;
			}
			maxx=max(maxx,tmp);
			ans=max(maxx,ans);
		}
		else
		{
			int tmp=0;
			for(int i=1;i<=n;i++)
			{
				
			}
		}
	}
	
	
	for(int i=1;i<=m;i++)
	{
		bool f=0;
		for(int j=0;j<=n;j++)
		{
			if(mp[j][i]==2)
			{
				f=1;
				break;
			}
		}
		if(f)
		{
			int tmp=0,maxx=0;
			for(int j=2;j<=n;j++)
			{
				if(mp[j][i]!=mp[j-1][i])
					tmp++;
				if(mp[j][i]==2)
					break;
			}
			maxx=max(maxx,tmp);
			tmp=0;
			for(int j=n-1;j>0;j--)
			{
				if(mp[j][i]!=mp[j+1][i])
					tmp++;
				if(mp[j][i]==2)
					break;
			}
			maxx=max(maxx,tmp);
			ans=max(maxx,ans);
		}
		else
		{
		}
	}
	cout<<ans<<endl;
//	int ans=0;
//	poi a,b;
//	a.x=sx,a.y=sy,a.su=0;
//	q.push(a);
//	memset(vis,0,sizeof(vis));
//	//cout<<sx<<" "<<sy<<endl;
//	while(q.size()){
//		a=q.front();
//		q.pop();
//		tt=a.su;
//		an=max(an,tt);
//		vis[a.x][a.y]=1;
//		dfs1(a.x,a.y);
//	}
//	if(mp[sx][sy]==1)an-=1;
//	cout<<an<<endl;
}
