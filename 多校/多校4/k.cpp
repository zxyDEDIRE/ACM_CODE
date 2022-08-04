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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
ll dp[10][10];
int n;
int f(int x)
{
	int cnt=0;
	while(x)x/=10,cnt++;
	return cnt;
}
void solve()
{
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ll x=i-1;
		ll y=i;
		ll len=f(i);
		dp[0][0]=i;
		for(int j=1;j<=len;j++)
		{
			for(int k=0;k<=9;k++)
			{
				
			}
		}
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}