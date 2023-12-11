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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[maxn][2];
int p[maxn][2];
int a[maxn];
int b[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
		a[i]=n*2-i;
	a[n]=n*2;
	for(int i=1;i<=n;i++)
		b[i]=i;

	for(int i=2;i<n-1;i+=4)
	{
		swap(a[i],a[i+1]);
	}
	for(int i=1;i<n;i+=4)
	{
		swap(b[i],b[i+1]);
	}
	

	for(int i=1;i<=n;i++)
	{
		if(i&1)p[i][0]=a[i];
		else p[i][0]=b[i];
	}
	for(int i=1;i<=n;i++)
	{
		if(i&1)p[i][1]=b[i];
		else p[i][1]=a[i];
	}



	for(int j=0;j<=1;j++)
	{
		for(int i=1;i<=n;i++)
			cout<<p[i][j]<<" ";
		cout<<endl;
	}

	// memset(dp,inf,sizeof(dp));

	// dp[0][0]=0;
	// dp[0][1]=INF;
	// for(int i=1;i<=n;i++)
	// {
	// 	dp[i][0]=dp[i-1][0]+p[i][0];
	// 	dp[i][1]=min({dp[i-1][1]+p[i][1],dp[i][0]+p[i][1]});
	// }
	// for(int j=0;j<=1;j++)
	// {
	// 	for(int i=1;i<=n;i++)
	// 		cout<<dp[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<dp[n][1]<<endl;

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