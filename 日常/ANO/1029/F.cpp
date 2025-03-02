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
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=300;
int dp[maxn][maxn];
int p[maxn];
int n,m;
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)
			f[i][0]=p[i];
		int t=log(n)/log(2)+1;
		for(int j=1;j<t;j++)
			for(int i=1;i<=n-(1<<j)+1;i++)
				f[i][j]=max(f[i][j-1],f[i+(1<<(j-1))][j-1]);
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return max(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	memset(dp,INF,sizeof(dp));
	st.init();
	for(int i=1;i<=n;i++)
		dp[i][1]=st.query(1,i)*i;
	st.init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			for(int k=2;k<=m;k++)
				dp[i][k]=min(dp[i][k],dp[j][k-1]+st.query(j+1,i)*(i-j));
	cout<<dp[n][m]<<endl;
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