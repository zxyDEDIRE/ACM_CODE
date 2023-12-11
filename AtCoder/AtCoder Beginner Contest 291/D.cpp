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
int a[maxn];
int b[maxn];
int dp[maxn][2];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	// for(int i=1;i<=n;i+/+)
		// cin>>b[i];
	dp[1][0]=dp[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]!=a[i-1])
			dp[i][0]+=dp[i-1][0];
		if(a[i]!=b[i-1])
			dp[i][0]+=dp[i-1][1];
		if(b[i]!=a[i-1])
			dp[i][1]+=dp[i-1][0];
		if(b[i]!=b[i-1])
			dp[i][1]+=dp[i-1][1];
		dp[i][0]%=mod;
		dp[i][1]%=mod;
	}
	// cout<<endl;/
	// for(int i=1;i<=n;i++)
		// cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
	cout<<(dp[n][0]+dp[n][1])%mod<<endl;
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