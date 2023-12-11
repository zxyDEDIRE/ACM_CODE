/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int a[maxn],b[maxn];
int dp[100][10000];
int n,x;
void solve()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=10000;j>=1;j--)
		{
			if(j>=a[i])dp[i][j]=max(dp[i][j],dp[i-1][j-a[i]]);
			if(j>=b[i])dp[i][j]=max(dp[i][j],dp[i-1][j-b[i]]);
		}
	}
	if(dp[n][x])cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}