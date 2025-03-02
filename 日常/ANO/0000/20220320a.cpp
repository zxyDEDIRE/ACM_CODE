#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100005;
ll a[maxn];
ll dp[maxn];
ll n;
int main()
{
	memset(dp,0x3f3f,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dp[1]=0;
	for(int i=1;i<=n;i++)
		for(int j=max(1,i-500);j<i;j++)
			dp[i]=min(dp[i],dp[j]+1ll*(i-j)*(i-j)*(i-j)*a[i]);
	cout<<dp[n]<<endl;
	return 0;
} 
