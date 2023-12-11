/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=4e3+100;
int dp[N];
int n,a,b,c;
void solve()
{
	cin>>n>>a>>b>>c;
	memset(dp,-1,sizeof(dp));
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		if(i-a>=0&&dp[i-a]!=-1)
			dp[i]=max(dp[i],dp[i-a]+1);
		if(i-b>=0&&dp[i-b]!=-1)
			dp[i]=max(dp[i],dp[i-b]+1);
		if(i-c>=0&&dp[i-c]!=-1)
			dp[i]=max(dp[i],dp[i-c]+1);
	}
	cout<<dp[n]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}