/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
map<int,int>dp[22][22];
int p[22][22];
int n,res;
void dfs1(int x,int y,int ans)
{
	if(x+y>=n)
	{
		dp[x][y][ans]++;
		return ;
	}
	else
	{
		dfs1(x+1,y,ans^p[x+1][y]);
		dfs1(x,y+1,ans^p[x][y+1]);
	}
}
void dfs2(int x,int y,int ans)
{
	if(x+y<=n)
	{
		//cout<<dp[x][y][ans^p[x][y]]<<endl;;
		res+=dp[x][y][ans^p[x][y]];
		return ;
	}
	else
	{
		dfs2(x-1,y,ans^p[x-1][y]);
		dfs2(x,y-1,ans^p[x][y-1]);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>p[i][j];
	dfs1(1,1,p[1][1]);
	dfs2(n,n,p[n][n]);
	cout<<res<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}