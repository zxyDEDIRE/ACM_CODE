#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=1e3+100;
ll dp[N][N];
int mp[N][N];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i*2-1;j++)dp[i][j]=-INF;
	dp[1][1]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i*2-1;j++){
			int x;cin>>x;
			dp[i][j]+=x;
		}
		for(int j=1;j<=i*2-1;j++)
		{
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
			dp[i+1][j+2]=max(dp[i+1][j+2],dp[i][j]);
		}
	}
	int len=n*2-1;len=ceil(len*0.5);
	ll ma=-INF;
	for(int i=max(1,len-k);i<=min(n*2-1,len+k);i++){
		ma=max(ma,dp[n][i]);
	}
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
  1 2 3 4 
1 2 3 4 5 6
*/