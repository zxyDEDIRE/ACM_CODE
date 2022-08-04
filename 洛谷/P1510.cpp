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
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int k[maxn],m[maxn];
int dp[maxn];
int v,n,c;
void solve()
{
	cin>>v>>n>>c;
	for(int i=1;i<=n;i++)
	{
		cin>>k[i]>>m[i];
	}
	for(int i=1;i<=v+10000;i++)
		dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=v+10000;j>=0;j--)
		{
			if(j>=k[i])dp[j]=min(dp[j],dp[j-k[i]]+m[i]);
		}
	}
	int mi=INF;
	for(int i=v;i<=v+10000;i++)
		mi=min(mi,dp[i]);
	if(mi>c)cout<<"Impossible";
	else cout<<c-mi<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}