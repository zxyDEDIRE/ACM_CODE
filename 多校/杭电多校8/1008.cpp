/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn];
int dp[maxn][4];
int n;
void dfs(int x,int f)
{
	dp[x][1]=1;
	dp[x][2]=1;
	int tot=0;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==f)continue;
		dfs(y,x);
		tot+=dp[y][0];
		
	}
	for(int i=0;i<v[x].size();i++)
	{
		dp[x][0]+=max({dp[y][0],dp[y][1],dp[y][2]});
		dp[x][1]+=tot;
		dp[x][2]=max(dp[x][2],dp[y][1]+1+tot-dp[y][0]);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		v[i].clear(),dp[i][0]=dp[i][2]=dp[i][1]=0;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,1);
	int ans=max(dp[1][0],dp[1][1]);
	ans=max(ans,dp[1][2]);
	cout<<ans<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int size(512<<20);  // 512M
	__asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	int __;cin>>__;
	while(__--)
		solve();
	exit(0);
	return 0;
}
/*
1
5
1 2
2 3
3 4 
4 5
*/