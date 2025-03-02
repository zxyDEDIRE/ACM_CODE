#include<bits/stdc++.h>
using namespace std;
#define int long long
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int maxn=100;
bool vis[maxn][maxn];
char mp[maxn][maxn];
char res[maxn][maxn];
int n,m,mi;

void dfs(int x,int y,int step)
{
	int sum=0;
	for(int i=0;i<8;i++)
		if(mp[x+dx[i]][y+dy[i]]=='C')sum++;
	if(sum>=3)return ;

	mp[x][y]='C';

	if(x==n&&y==m)
	{
		if(step>mi)
		{
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					res[i][j]=mp[i][j];
		}
	}


	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m)continue;
		if(mp[xx][yy]!='#'&&vis[xx][yy]==0&&mp[xx][yy]=='.')
		{
			vis[xx][yy]=1;
			dfs(xx,yy,step+1);
			vis[xx][yy]=0;
		}
	}

}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int cas =0;
	while(1)
	{
		cin>>n>>m;
		if(n==0)break;
		cout<<(++cas)<<endl;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[i][j];

		dfs(1,1,0);

		cout<<"Case "<<cas<<":"<<"\n";

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<res[i][j];
			cout<<endl;
		}
	}
}