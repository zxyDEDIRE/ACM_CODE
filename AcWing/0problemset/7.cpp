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
int dp[maxn];
int a[maxn],b[maxn];
int n,m,cnt;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==-1)z=1;
		else if(z==0)z=m/x;
		int k=1;
		while(z>=k)
		{
			cnt++;
			a[cnt]=x*k;
			b[cnt]=y*k;
			z-=k;
			k*=2;
		}
		if(z>0)
		{
			cnt++;
			a[cnt]=z*x;
			b[cnt]=z*y;
		}
	}
	n=cnt;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=a[i];j--)
			dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
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