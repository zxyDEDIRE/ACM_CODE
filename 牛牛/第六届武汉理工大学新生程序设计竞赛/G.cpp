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
const int maxn=1e5+100;
int dp[maxn][8];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		int ans=0;
		for(int j=1;j<=7;j++)
		{
			for(int _i=max(1ll,j-k);_i<=min(7ll,j+k);_i++)
				dp[i][j]=max(dp[i][j],dp[i-1][_i]);
		}
		dp[i][x]++;
	}
	int ans=0;
	for(int i=1;i<=7;i++){
		ans=max(ans,dp[n][i])
	}
	cout<<n-ans<<endl;
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
7 6
1 2 3 4 3 2 1


6 1
1 2 4 5 6 7
*/