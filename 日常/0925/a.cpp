#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e4;
ll sum[maxn];
ll p[maxn];
ll a[maxn];
ll dp[111][111];
ll n;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		p[i]=p[i-1]+a[i]; 
		if(i>1)
		{
			sum[i]=(a[i]-a[i-1])*(a[i]-a[i-1])+sum[i-1];
		}
	}
	a[0]=a[1];
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=min(i-1ll,n-2);j++)
		{
			for(int k=0;k<=j;k++)
			{
				dp[i][j]=max(dp[i][j],dp[i-k-1][j-k]+(a[i]-a[i-k-1])*(a[i]-a[i-k-1]));
			}
		}
	}

	vector<int>v;
	for(int i=2;i<n-1;i+=2)
		v.push_back(dp[n][i]);

	while(v.size()!=n)
		v.push_back(dp[n][n-2]);
	for(int i=0;i<n;i++)
		printf("%lld\n",v[i]);
	
	
}
/*
6
0 6 6 6 6 6

5
1 2 3 4 5

9
4 1 1 0 0 0 2 2 2

10
1 5 6 7 7 7 7 9 11 13
54
62
78
144
144
144
144
144
144
144

10
1 5 6 7 7 7 7 9 11 13
*/
