/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[101][101];
int a[maxn];
int p[maxn];
int n,m,d;
void solve()
{
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	memset(dp,-1,sizeof(dp));
	for(int i=0;i<=n;i++)
		dp[0][0]=0;

	
	for(int k=0;k<=m;k++)
	{
		for(int j=0;j<d;j++)
		{ 
			
			for(int i=1;i<=n;i++)
			{
				if(dp[j][k]!=-1){
					dp[(j+p[i])%d][k+1]=max(dp[(j+p[i])%d][k+1],dp[j][k]+p[i]);
					// cout<<i-1<<" "<<j<<" "<<k<<" "<<dp[i-1][j][k]<<endl;
					// cout<<i<<" "<<(j+p[i])%d<<" "<<k+1<<" "<<dp[i][(j+p[i])%d][k+1]<<endl;
					// cout<<endl;
				}
			}
		}
	}
	cout<<dp[0][m]<<endl;

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