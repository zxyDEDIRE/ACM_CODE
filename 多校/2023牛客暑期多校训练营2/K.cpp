/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn][4];
int p[maxn];
int t[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>t[i];
	// for(int i=1;i<=n;i++)
	// {
	// 	if(t[i]==1)
	// 	{
	// 		dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
	// 		dp[i][1]=max({dp[i-1][0],dp[i-1][1],dp[i-1][3]})+p[i];
	// 		dp[i][2]=max({dp[i-1][0],dp[i-1][2],dp[i-1][3]})+p[i+1];
	// 		dp[i][3]=max({dp[i-1][0],dp[i-1][3]})+p[i-1];
	// 	}
	// 	else
	// 	{
	// 		dp[i][0]=max({dp[i-1][0],dp[i-1][1],dp[i-1][2],dp[i-1][3]});
	// 	}
	// }

	for(int i=1;i<=n;i++)
	{
		if(t[i]==1)
		{
			
		}
	}



	cout<<max({dp[n][0],dp[n][1],dp[n][2],dp[n][3]})<<endl;
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
/*
4
3 1 1 3
0 1 1 0

4
1 1 3 3
1 1 0 0 


3
1 2 3
1 1 0

3
3 2 1
0 1 1

1 1 0


*/