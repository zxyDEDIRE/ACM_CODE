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
int dp[maxn][2];
int p[maxn];
int n,m,k;
void solve()
{
	cin>>n>>k;
	for(int i=0;i<=n;i++)
		dp[i][0]=dp[i][1]=INF;
	cin>>p[1];dp[1][0]=dp[1][1]=p[1];
	cin>>p[2];
	dp[2][0]=p[1]*min(k,p[2]);
	dp[2][1]=p[1]*(p[2]-min(k,p[2]));
	for(int i=3;i<=n;i++)
	{
		cin>>p[i];
		dp[i][0]=min(dp[i][0],dp[i-1][0]+(p[i-1]-min(k,p[i-1]))*min(k,p[i]));
		dp[i][0]=min(dp[i][0],dp[i-1][1]+min(k,p[i-1])*min(k,p[i]));
		dp[i][1]=min(dp[i][1],dp[i-1][0]+(p[i-1]-min(k,p[i-1]))*(p[i]-min(k,p[i])));
		dp[i][1]=min(dp[i][1],dp[i-1][1]+min(k,p[i-1])*(p[i]-min(k,p[i])));
	}
	int x=dp[n-1][0]+(p[n-1]-min(k,p[n-1]))*p[n];
	int y=dp[n-1][1]+min(k,p[n-1])*p[n];
	cout<<min(x,y)<<endl;


}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
5 0
2 0 1 3 4

1
5 5
4 3 5 6 4
*/