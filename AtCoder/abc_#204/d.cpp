/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dp[maxn];
int p[maxn];
int n,sum;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=sum/2;j>=p[i];j--)
		{
			dp[j]=max(dp[j],dp[j-p[i]]+p[i]);
		}
	}
	// cout<<sum<<endl;
	// cout<<sum/2<<endl;
	// cout<<dp[sum/2]<<endl;
	cout<<max(dp[sum/2],sum-dp[sum/2])<<endl;


}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}