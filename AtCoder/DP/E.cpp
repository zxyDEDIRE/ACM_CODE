/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
int w[maxn],v[maxn];
int dp[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=0;i<=1e5;i++)
		dp[i]=INF;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1e5;j>=1;j--)
		{
			if(j>=v[i])
				dp[j]=min(dp[j],dp[j-v[i]]+w[i]);
		}
	}
	for(int i=1e5;i>=0;i--)
		if(dp[i]<=m){
			cout<<i<<endl;
			return ;
		}
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