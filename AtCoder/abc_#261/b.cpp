/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=2000;
char mp[maxn][maxn];
int vis[maxn][maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
		}
	}
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]=='-'&&i!=j)flag=0;
			if(i==j&&mp[i][j]!='-')flag=0;
			if(vis[i][j]==0)
			{
				if(mp[i][j]=='W')
				{
					vis[i][j]=1;
					vis[j][i]=2;
				}
				else if(mp[i][j]=='L')
				{
					vis[i][j]==2;
					vis[j][i]=1;
				}
				else if(mp[i][j]=='D')
				{
					vis[i][j]=vis[j][i]=3;
				}
			}
			else
			{
				if(mp[i][j]=='W'&&vis[i][j]!=1&&vis[j][i]!=2)flag=0;
				if(mp[i][j]=='L'&&vis[i][j]!=2&&vis[j][i]!=1)flag=0;
				if(mp[i][j]=='D'&&vis[i][j]!=3&&vis[j][i]!=3)flag=0;
			}
		}
	}
	if(flag)cout<<"correct"<<endl;
	else cout<<"incorrect"<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}