#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
struct node{
	int x,y;
}a[maxn];
int dp[maxn];
int p[maxn];
int n,len;
bool cmp(node a,node b)
{
	if(a.y!=b.y)return a.y<b.y;
	return a.x<b.x;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i].x>>a[i].y;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)p[i]=a[i].x;

	dp[0]=1e9;
	len=0;
	for(int i=1;i<=n;i++)
	{
		if(dp[len]>p[i])dp[++len]=p[i];
		else
		{
			int fl=upper_bound(dp+1,dp+1+len,p[i],greater<int>() )-dp;
			dp[fl]=p[i];
		}
	}
	cout<<len<<endl;
}