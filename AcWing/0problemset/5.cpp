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
int v[maxn],val[maxn];
int n,V,m=0;
void solve()
{
	cin>>n>>V;
	for(int i=1;i<=n;i++)
	{
		int x,y,z,t=1;
		cin>>x>>y>>z;
		while(z>=t)
		{
			m++;
			v[m]=x*t;
			val[m]=y*t;
			z-=t;
			t*=2;
		}
		if(z>0)
		{
			m++;
			v[m]=x*z;
			val[m]=y*z;
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=V;j>=v[i];j--)
		{
			dp[j]=max(dp[j],dp[j-v[i]]+val[i]);
		}
	}
	cout<<dp[V]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}