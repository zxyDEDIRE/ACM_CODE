/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const ll INF=0x3f3f3f3f3f3f;
const int maxn=1e6;
//ll dp[maxn][3];
ll dp[maxn];
ll p[maxn];
ll n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		//dp[i][0]=dp[i][1]=-INF;
		dp[i]=-INF;
	}
	//dp[0][0]=dp[0][1]=0;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		dp[i]=dp[i-1]+max(p[i]-k,p[i]/2);
	}
	cout<<dp[n]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}