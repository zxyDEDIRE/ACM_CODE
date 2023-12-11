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
const int maxn=1011;
bool vis[maxn][maxn];
int dp[maxn][maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		vis[x][y]=1;
	}
	dp[1][1]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
				dp[i][j]+=dp[i-1][j]+dp[i][j-1];
			dp[i][j]%=100003;
		}
	}
	cout<<dp[n][n];
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}