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
const int maxn=1e6;
int dp[maxn][2];
int a[maxn],b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	a[0]=1;
	b[0]=1;
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][1]+abs(b[i-1]-b[i]),dp[i-1][0]+abs(a[i-1]-b[i]))+b[i]-a[i]+1;
		dp[i][1]=min(dp[i-1][1]+abs(b[i-1]-a[i]),dp[i-1][0]+abs(a[i-1]-a[i]))+b[i]-a[i]+1;
		if(i==1)dp[i][0]--,dp[i][1]--;
	}
	//cout<<dp[n][0]<<" "<<dp[n][1]<<endl;
	cout<<min(dp[n][0]+abs(n-a[n]),dp[n][1]+abs(n-b[n]))<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}