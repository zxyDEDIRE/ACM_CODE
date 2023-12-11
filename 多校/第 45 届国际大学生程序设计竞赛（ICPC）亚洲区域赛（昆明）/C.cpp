#include <bits/stdc++.h>
using namespace std;

const int INF=1e9+7;
const int N = 5010;
int p[N];
int n;
int dp[N][N];


vector<vector<int>> f(int l,int r)
{
	int mid=(l+r)>>1;
	auto _a=f(l,mid);
	auto _b=f(mid+1,r);
	vector<vector<int>> dp=vector<vector<int>>(n+1,vector<int>(n+1,INF));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int k=1;k<=n;k++)
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
	return dp;
}
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	f(1,n);
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int t;
	cin >> t;
	while(t --){
		solve();
	}
	return 0;
}