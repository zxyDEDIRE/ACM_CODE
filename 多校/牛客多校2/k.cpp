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
const int mod=1e9+7;
const int maxn=300;
ll dp[maxn][maxn][maxn];
string str;
int n,m;
void solve()
{
	cin>>n>>m>>str;
	str=" "+str;
	for(int i=0;i<=m;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=i;k++)
				dp[i][j][k]=0;
	dp[0][0][0]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			for(int k=0;k<=i;k++)
			{
				if(j==0)
				{
					dp[i][j][k+1]+=dp[i-1][j][k];
					dp[i][j][k]+=dp[i-1][j][k+1];
					dp[i][j][k]%=mod;
					dp[i][j][k+1]%=mod;
					continue;
				}
				if(str[j]=='(')
				{
					dp[i][j][k+1]+=dp[i-1][j-1][k];
					dp[i][j][k]+=dp[i-1][j][k+1];
					dp[i][j][k]%=mod;
					dp[i][j][k+1]%=mod;
				}
				else
				{
					dp[i][j][k]+=dp[i-1][j-1][k+1];
					dp[i][j][k+1]+=dp[i-1][j][k];
					dp[i][j][k]%=mod;
					dp[i][j][k+1]%=mod;
				}
			}
		}
	}
	cout<<dp[m][n][0]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*

*/