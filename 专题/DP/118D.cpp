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
const int mod=1e8;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[111][111][22][2];
int n1,n2,k1,k2;
void solve()
{
	cin>>n1>>n2>>k1>>k2;
	dp[0][0][0][0]=1;
	dp[0][0][0][1]=1;
	for(int i=0;i<=n1;i++)
	{
		for(int j=0;j<=n2;j++)
		{
			for(int a=1;a<=min(k1,i);a++)
			{
				if(i==0)continue;
				(dp[i][j][a][0]+=dp[i-1][j][a-1][0])%=mod;
				if(a==1)
				{
					for(int b=1;b<=min(j,k2);b++)
						(dp[i][j][a][0]+=dp[i-1][j][b][1])%=mod;
				}
			}
			for(int b=1;b<=min(k2,j);b++)
			{
				if(j==0)continue;
				(dp[i][j][b][1]+=dp[i][j-1][b-1][1])%=mod;
				if(b==1)
				{
					for(int a=1;a<=min(i,k1);a++)
						(dp[i][j][b][1]+=dp[i][j-1][a][0])%=mod;
				}
			}
		}
	}

	int ans=0;
	for(int i=1;i<=max(k1,k2);i++)
	{
		if(i<=k1)(ans+=dp[n1][n2][i][0])%=mod;
		if(i<=k2)(ans+=dp[n1][n2][i][1])%=mod;
	}
	cout<<ans<<endl;
	// cout<<dp[1][0][1][0]<<endl;
	// cout<<dp[1][1][1][1]<<endl;

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