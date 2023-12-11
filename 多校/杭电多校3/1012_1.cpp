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
const int mod=998244353;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int a[maxn],b[maxn],p[maxn];
ll dp[maxn][2];
int n;
ll dfs(int x,int y,int fl)
{
	if(x>n&&y>n)return 1;
	if(dp[x+y-1][fl])return dp[x+y-1][fl];

	ll ans=0;

	if(p[x+y-1]==a[x]&&x<=n)
	{
		ans+=dfs(x+1,y,0);
		ans%=mod;
	}

	if(p[x+y-1]==b[y]&&y<=n)
	{
		ans+=dfs(x,y+1,1);
		ans%=mod;
	}

	return dp[x+y-1][fl]=ans;

}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=n*2;i++)
	{
		dp[i][0]=dp[i][1]=0;
		cin>>p[i];
	}
	dp[0][0]=dp[0][1]=0;
	for(int i=n*2;i<=n*2+100;i++)
		dp[i][0]=dp[i][1]=0;
	ll ans=0;
	if(a[1]==p[1])ans+=dfs(2,1,0);ans%=mod;
	if(b[1]==p[1])ans+=dfs(1,2,1);ans%=mod;
	cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}