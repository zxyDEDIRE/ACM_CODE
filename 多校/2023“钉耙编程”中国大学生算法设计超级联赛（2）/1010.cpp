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
const int maxn=3e4+100;
const int N=2e4+10;
ll dp[N][2010];
int p[maxn];
int n,m;
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=p[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		for(int j=0;j<=m;j++)
			dp[i][j]=INF;
	for(int j=0;j<=m;j++)
		dp[0][j]=0;
	st.init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			if(m-j>=0&&i-j+1>=1)
			{
				dp[i][j]=min(dp[i][j],dp[i-j][min(i-j,m-j)]+st.query(i-j+1,i));
				// cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
				// cout<<i-j<<" "<<m-j<<" "<<dp[i-j][min(i-j,m-j)]<<" "<<st.query(i-j+1,i)<<endl;
				// cout<<endl;
			}
		}
	}
	ll mi=dp[n][1];
	for(int i=1;i<m;i++)
		mi=min(mi,dp[n][i]);
	cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1
7 7
1 5 7 2 1 4 8
*/