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
const int mod=1e9+7;
const int N=100;
int dp[N][N][N];
int last[N];
int n,m;
void solve()
{
	memset(dp,0,sizeof(dp));
	memset(last,0,sizeof(last));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		last[y]=max(last[y],x);
	}
	dp[0][0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=j;k++)
			{
				if(k<last[i])continue;
				dp[i+1][j][k]+=6*dp[i][j][k];dp[i+1][j][k]%=mod;
				dp[i+1][i+1][j]+=2*dp[i][j][k];dp[i+1][i+1][j]%=mod;
				dp[i+1][i+1][i+1]+=2*dp[i][j][k];dp[i+1][i+1][i+1]%=mod;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			if(j<last[n])continue;
			ans+=dp[n][i][j];ans%=mod;
		}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
2 1
1 2

10
90
01
09

19
99

91
99

*/