/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=111;
bitset<maxn>vis[maxn];
string mp[maxn];
int p[maxn][maxn];
int n,m,ans;
void dfs(int x,int y)
{
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy]||mp[xx][yy]=='*')continue;
		vis[xx][yy]=1;
		ans++;
		dfs(xx,yy);
	}
	p[x][y]=ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		mp[i]=" "+mp[i];
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j]||mp[i][j]=='*')continue;
			ans=1;
			vis[i][j]=1;
			dfs(i,j);
		}
	}

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cout<<p[i][j];
		}
		cout<<endl;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}