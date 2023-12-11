/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[5];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==1)
		{
			dp[1]=dp[1]+1;
			dp[3]=max(dp[3],dp[2])+1;
		}
		else
		{
			dp[2]=max(dp[2],dp[1])+1;
			dp[4]=max(dp[4],dp[3])+1;
		}
		ma=max({ma,dp[1],dp[2],dp[3],dp[4]});
	}
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
100
1 1 1 2 1 1 1 2 2 1 2 1 1 1 2 1 2 2 2 1 1 1 1 2 2 2 1 1 1 2 1 2 1 2 2 2 1 1 1 1 1 1 1 2 1 1 2 2 1 1 1 1 1 1 1 1 2 1 1 1 2 2 2 1 1 2 2 2 1 2 1 1 1 1 2 1 2 1 1 1 2 2 1 2 2 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1
*/