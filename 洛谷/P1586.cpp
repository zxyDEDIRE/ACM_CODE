/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=40000;
ll dp[40000][5];
ll n;
void solve()
{
	cin>>n;
	ll ans=0;
	for (int i=1;i<=4;i++)
		ans+=dp[n][i];
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

	dp[0][0]=1;
	for (int i=1;i*i<=maxn;i++)
		for (int j=i*i;j<=maxn;j++)
			for (int sum=1;sum<=4;sum++) 
				dp[j][sum]+=dp[j-i*i][sum-1];

	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}