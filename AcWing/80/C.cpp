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
const int mod=1e8;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[111][111][22][22];
int n,m,la,lb;
void solve()
{
	cin>>n>>m>>la>>lb;
	dp[0][0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int a=0;a<=la&&a<=i;a++)
			{
				for(int b=0;b<=lb&&b<=j;b++)
				{
					if(i&&a==1)
						dp[i][j][a][0]+=dp[i-1][j][0][b];
					else if(i&&a>1&&b==0)
						dp[i][j][a][0]+=dp[i-1][j][a-1][0];

					if(j&&b==1)
						dp[i][j][0][b]+=dp[i][j-1][a][0];
					else if(j&&b&&a==0)
						dp[i][j][0][b]+=dp[i][j-1][0][b-1];

					dp[i][j][a][b]%=mod;
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=la;i++)
		ans+=dp[n][m][i][0],ans%=mod;
	for(int i=1;i<=lb;i++)
		ans+=dp[n][m][0][i],ans%=mod;
	cout<<ans<<endl;
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
/*
2 3 1 2
01101
01001
10110
11010
10101

dp[2][2][1][0]

dp[1][2][0][0]=0;
dp[1][2][0][1]=1;
dp[1][2][0][2]=2;
*/