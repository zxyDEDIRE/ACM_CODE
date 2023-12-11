/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=3e3+100;
double dp[N][N];
double p[N];
int n;
void solve()
{
	cin>>n;
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
		cin>>p[i],dp[i][0]=1.0*dp[i-1][0]*(1-p[i]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i;j++)
		{
			dp[i][j]=1.0*dp[i-1][j-1]*p[i]+1.0*dp[i-1][j]*(1-p[i]);
		}
	}
	double ans=0;
	for(int i=(n+1)/2;i<=n;i++)
		ans+=dp[n][i];
	printf("%.9lf",ans);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}