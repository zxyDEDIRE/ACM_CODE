/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
const int N=1e3+100;
int dp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=INF;
	dp[0][1]=0;
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+((m+j-1)/j-1)*(n-i));
			dp[i][j+1]=min(dp[i][j+1],dp[i][j]+((m+j-1)/j-1)*(n-i));
		}
	}
	int mi=INF;
	for(int i=0;i<=n;i++)
		mi=min(mi,dp[i][m]);
	for(int i=1;i<=m;i++)
		mi=min(mi,dp[n][i]);
	cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}