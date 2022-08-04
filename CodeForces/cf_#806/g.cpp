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
const int maxn=1e5+2;
ll dp[maxn][35];
ll p[maxn];
ll n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=32;j++)
			dp[i][j]=0;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	ll ma=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=32;j++)
		{
			dp[i][j]=dp[i-1][j]+(p[i]>>j)-k;
			if(j>=1)
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+(p[i]>>j));
			ma=max(ma,dp[i][j]);
		}
	}
	cout<<ma<<endl;
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