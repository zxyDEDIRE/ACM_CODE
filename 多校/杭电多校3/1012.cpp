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
map<pii,ll>dp;
int n,cnt;
int dfs(int x,int y)
{
	if(dp[{x,y}])return dp[{x,y}];
	if(x>n&&y>n)return dp[{x,y}]=1;

	ll ans=0;

	if(p[x+y-1]==a[x]&&x<=n)
	{
		ans+=dfs(x+1,y);
		ans%=mod;
	}

	if(p[x+y-1]==b[y]&&y<=n)
	{
		ans+=dfs(x,y+1);
		ans%=mod;
	}
	return dp[{x,y}]=ans;
}
void solve()
{
	cin>>n;
	dp.clear();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=2*n;i++)
		cin>>p[i];
	cout<<dfs(1,1)<<endl;
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