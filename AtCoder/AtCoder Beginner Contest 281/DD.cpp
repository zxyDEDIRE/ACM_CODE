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
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[111][111][111];
int p[maxn];
int n,m,d;
void solve()
{
	cin>>n>>m>>d;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	memset(dp,-1,sizeof(dp));
	dp[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<i;j++)
		{
			for(int mod=0;mod<d;mod++)
			{
				for(int k=0;k<=m;k++)
				{
					if(dp[j][mod][k]!=-1){
						dp[i][(mod+p[i])%d][k+1]=max(dp[i][(mod+p[i])%d][k+1],dp[j][mod][k]+p[i]);
					}
				}
			}
		}
	}
	int ma=-1;
	for(int i=m;i<=n;i++){
		ma=max(ma,dp[i][0][m]);
	}
	cout<<ma<<endl;
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