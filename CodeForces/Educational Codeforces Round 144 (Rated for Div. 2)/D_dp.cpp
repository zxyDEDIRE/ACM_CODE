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
const int INF=1e18+7;
const int maxn=1e6+100;
int dp[maxn][33];
int p[maxn];
int n,k,x;
void solve()
{
	cin>>n>>k>>x;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=-INF;
	dp[0][0]=0;
	int ma=0;
	for(int j=0;j<=k;j++)
	{
		for(int i=1;i<=n;i++)
		{
			if(dp[i-1][j]>=0)
			{
				dp[i][j]=dp[i-1][j]+p[i]-x;
			}
			else dp[i][j]=p[i]-x;

			if(j>=1&&dp[i-1][j-1]>=0)
			{
				dp[i][j]=dp[i-1][j-1]+p[i]+x;
			}


			if(j==k||j+(n-i)>=k){
				cout<<i<<" "<<j<<" "<<j+(n-i)<<" "<<dp[i][j]<<endl;
				ma=max(ma,dp[i][j]);
			}
		}
	}
	cout<<ma<<endl;
	cout<<dp[1][1]<<endl;//-4
	cout<<dp[2][1]<<endl;//3
	cout<<dp[3][1]<<endl;//20
	cout<<dp[4][1]<<endl;//20-3+8
	cout<<dp[5][1]<<endl;//25+7+8
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
*/