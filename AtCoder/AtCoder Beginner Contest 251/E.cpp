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
const int INF=1e18+7;
const int maxn=1e6+100;
int dp[maxn][3];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ans=1e18;
	dp[1][0]=p[1];
	dp[1][1]=INF;
	for(int i=2;i<=n;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+p[i];
		dp[i][1]=dp[i-1][0];
	}
	ans=min({ans,dp[n][0],dp[n][1]});

	dp[1][0]=p[1]+p[n];
	dp[1][1]=p[n];
	for(int i=2;i<n;i++)
	{
		dp[i][0]=min(dp[i-1][0],dp[i-1][1])+p[i];
		dp[i][1]=dp[i-1][0];
	}
	ans=min({ans,dp[n-1][0],dp[n-1][1]});
	cout<<ans<<endl;
}
int a[maxn];
void solve1()
{
	int n=3;
	a[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			a[j+i]+=a[j];
		}
		cout<<a[n]<<endl;
	}
	cout<<a[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve1();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
