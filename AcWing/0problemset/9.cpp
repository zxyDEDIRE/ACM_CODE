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
const int maxn=1e6;
vector<int>v[maxn];
int a[maxn],b[maxn];
int dp[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int k=1;k<=n;k++)
	{
		int s;
		cin>>s;
		for(int i=1;i<=s;i++)
			cin>>a[i]>>b[i];
		for(int j=m;j>=0;j--)
		{
			for(int i=1;i<=s;i++)
			{
				if(j>=a[i])
					dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
			}
		}
	}
	cout<<dp[m]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}