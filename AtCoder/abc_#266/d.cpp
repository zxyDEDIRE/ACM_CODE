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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int dp[maxn][5];
int p[maxn][5];
int n,m=0;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int t,x,a;
		cin>>t>>x>>a;
		p[t][x]=a;
		m=max(m,t);
	}
	for(int i=m;i>=0;i--)
	{
		for(int j=0;j<=4;j++)
		{
			if(j!=0)dp[i][j]=max(dp[i][j],dp[i+1][j-1]);
			if(j!=4)dp[i][j]=max(dp[i][j],dp[i+1][j+1]);
			dp[i][j]=max(dp[i][j],dp[i+1][j]);
			dp[i][j]+=p[i][j];
		}
	}
	cout<<dp[0][0]<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}