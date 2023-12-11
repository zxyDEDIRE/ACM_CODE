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
const int maxn=2000;
int dp[maxn][maxn];
int a[maxn],b[maxn],c[maxn];
int n,v,m;
void solve()
{
	cin>>n>>v>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i]>>c[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=v;j>=a[i];j--)
		{
			for(int k=m;k>=b[i];k--)
			{
				dp[j][k]=max(dp[j][k],dp[j-a[i]][k-b[i]]+c[i]);
			}
		}
	}
	cout<<dp[v][m]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}