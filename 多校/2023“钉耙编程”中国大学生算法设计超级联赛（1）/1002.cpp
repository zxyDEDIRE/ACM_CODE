/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e5+100;
vector<int>v[maxn];
ll dp[maxn][3];
ll a[maxn];
int n;
void dfs(int x,int fa)
{
	ll sum=0;
	dp[x][0]=a[x];
	dp[x][1]=0;
	dp[x][2]=INF;
	for(auto y:v[x])
		if(y!=fa)
		{
			dfs(y,x);
			dp[x][0]+=min({dp[y][0],dp[y][1],dp[y][2]});
			dp[x][1]+=min(dp[y][0],dp[y][2]);
			sum+=min(dp[y][0],dp[y][2]);
		}
	for(auto y:v[x])
		if(y!=fa)
			dp[x][2]=min(dp[x][2],sum-min(dp[y][0],dp[y][2])+dp[y][0]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	cout<<min(dp[1][0], dp[1][2])<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
	cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}