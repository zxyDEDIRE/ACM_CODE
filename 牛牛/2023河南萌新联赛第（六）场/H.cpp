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
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn];
int p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;cin>>x;
			p[i]=max(p[i],x);
		}
	}
	dp[1]=p[1];
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=max(dp[i],dp[i-1]);
		if(i+k<=n)
			dp[i+k]=max(dp[i+k],dp[i]+p[i+k]);
		ma=max({ma,dp[i],dp[i+k]});
	}
	cout<<dp[n]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}