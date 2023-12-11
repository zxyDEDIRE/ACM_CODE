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
const int INF=1e18+7;
const int maxn=1e4+100;
int a[maxn],b[maxn];
int dp[maxn][2];
int n,x;
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=0;i<=x;i++)
		dp[i][0]=dp[i][1]=-1;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=x;j>=0;j--)
		{
			if(j>=a[i]/2)
			{
				if(dp[j-(a[i]/2)][1]!=-1)
				dp[j][0]=max(dp[j][0], dp[j-(a[i]/2)][1]+b[i]);
			}
			if(j>=a[i])
			{
				if(dp[j-a[i]][0]!=-1)
				dp[j][1]=max(dp[j][1],dp[j-a[i]][0]+b[i]);
				if(dp[j-a[i]][1]!=-1)
				dp[j][1]=max(dp[j][1],dp[j-a[i]][1]+b[i]);
			}
			if(j)
			{
				dp[j][0]=max(dp[j][0],dp[j-1][0]);
				dp[j][1]=max(dp[j][1],dp[j-1][0]);
			}
		}
	}
	// int ans=0;
	// for(int i=0;i<=x;i++)
	// {
	// 	ans=max(ans,dp[i][0]);
	// 	ans=max(ans,dp[i][1]);
	// }
	// cout<<ans<<endl;
	cout<<max(dp[x][0],dp[x][1])<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}