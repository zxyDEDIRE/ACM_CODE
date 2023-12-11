/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
const int N=555;
int dp[N][N];
int pre[maxn];
int p[maxn];
int n,m;
int f(int x,int y){
	return (p[y]-p[x])*(p[y]-p[x]);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++)
		pre[i]=pre[i-1]+f(i+1,i);

	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int len=j-i-1;
			for(int k=0;k+len<=m;k++)
			{
				dp[j][k+len]=max(dp[j][k+len],dp[i][k]+f(i,j));
			}
		}
	}
	cout<<dp[n][m]<<endl;
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