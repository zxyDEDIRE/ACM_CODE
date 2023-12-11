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
struct node{
	int x,y;
}p[maxn];
int dp[maxn];
int a[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;
	});

	for(int i=1;i<=n;i++)
		a[i]=p[i].y;
	int len=0;
	for(int i=1;i<=n;i++)
	{
		if(a[i]>dp[len])dp[++len]=a[i];
		else
		{
			int fl=lower_bound(dp+1,dp+1+len,a[i])-dp;
			dp[fl]=a[i];
		}
	}
	cout<<len<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}