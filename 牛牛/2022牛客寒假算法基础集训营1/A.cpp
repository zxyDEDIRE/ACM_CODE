/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e5+100;
int dp[maxn][10];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	// memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<9;j++)
		{
			if(dp[i-1][j])
				dp[i][(j+p[i])%9]+=dp[i-1][j],dp[i][(j+p[i])%9]%=mod;
			dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
		}
		dp[i][p[i]%9]++;
	}
	for(int i=1;i<9;i++)
		cout<<dp[n][i]%mod<<" ";
	cout<<dp[n][0]%mod<<endl;
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