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
const int N=2e3+100;
int dp[N][N];
int w[maxn];
int p[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i],w[i]%=m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=0;i<=n;i++)
		for(int j=0;j<m;j++)
			dp[i][j]=-1;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(dp[i-1][j]!=-1)
			dp[i][(j+w[i])%m]=max(dp[i][(j+w[i])%m],dp[i-1][j]+p[i]);
			
		}
	}
	cout<<dp[n][0]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}