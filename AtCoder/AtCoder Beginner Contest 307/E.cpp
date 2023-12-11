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
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn][4];
int n,m;
void solve()
{
	cin>>n>>m;
	dp[1][0]=1;
	dp[1][1]=0;
	for(int i=2;i<=n;i++)
	{
		dp[i][1]+=(dp[i-1][0]*(m-1))%mod+(dp[i-1][1]*(m-2))%mod;dp[i][1]%=mod;
		dp[i][0]+=dp[i-1][1];dp[i][0]%=mod;
		// cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	}
	cout<<(dp[n][1]*m)%mod<<endl;
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
/*
{
	0
	1
	2
}
{
	01
	02
	10
	20
	12
	21
}
*/