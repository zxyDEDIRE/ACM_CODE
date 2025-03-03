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
const int INF=1e9+7;
const int maxn=1e6+100;

class Solution {
public:
	int maxSum(vector<int>& p, int k, int m) {
		int n = p.size();
		vector<int>pre(n+2,0ll);pre[0]=p[0];
		for(int i=1;i<=n;i++)
			pre[i]=pre[i-1]+p[i-1];

		vector<vector<int>> dp(n+2,vector<int>(k+2,-1e9));
		for(int i=0;i<=n;i++)
			dp[i][0]=0;

		for(int j=1;j<=k;j++){
			int ma=-1e9;
			for(int i=j*m;i<=n;i++){
				ma = max(ma, dp[i-m][j-1] - pre[i-m]);
				if(ma != -1e9)
					dp[i][j] = max(dp[i-1][j], ma + pre[i]);
				else
					dp[i][j] = dp[i-1][j];
			}
		}


		// cout<<dp[3][1]<<endl;

		return dp[n][k];
	}
};
Solution b = Solution();
void solve()
{
	// vector<int> a={1,2,-1,3,3,4};
	vector<int> a= {-10,3,-1,-2};
	// vector<int> a={-2,-10,15,12,8,11,5};
	// vector<int> a={4,13,10,8};


	// int ans=b.maxSum(a,2,2);
	int ans=b.maxSum(a,4,1);
	// int ans=b.maxSum(a,3,2);
	// int ans=b.maxSum(a,3,1);

	cout<<"ans:"<<ans<<endl;
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
-2,-10,15,12,8,11,5

5 + 20 + 16
1 2 3 4 5 6
*/