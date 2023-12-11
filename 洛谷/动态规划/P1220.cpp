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
const int INF=1e15+7;
const int maxn=1e6+100;
const int N=100;
int dp[N][N][2];
int sum[maxn];
int pos[maxn];
int p[maxn];
int n,c;
int dfs(int l,int r,int fl)
{
	if(c<l&&c>r)return INF;
	if(l==r)return dp[l][r][fl]=0;
	if(dp[l][r][fl]!=INF)return dp[l][r][fl];
	if(fl==0&&l<c)//左端点
	{
		int x=dfs(l+1,r,0)+(pos[l+1]-pos[l])*(sum[n]-(sum[r]-sum[l]));
		int y=dfs(l+1,r,1)+(pos[r]-pos[l])*(sum[n]-(sum[r]-sum[l]));
		dp[l][r][fl]=min({dp[l][r][fl],x,y});
	}
	else if(fl==1&&r>c)
	{
		int x=dfs(l,r-1,0)+(pos[r]-pos[l])*(sum[n]-(sum[r-1]-sum[l-1]));
		int y=dfs(l,r-1,1)+(pos[r]-pos[r-1])*(sum[n]-(sum[r-1]-sum[l-1]));
		dp[l][r][fl]=min({dp[l][r][fl],x,y});
	}
	return dp[l][r][fl];
}
void solve()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
		cin>>pos[i]>>p[i];
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+p[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j][0]=dp[i][j][1]=INF;
	cout<<min(dfs(1,n,0),dfs(1,n,1))<<endl;
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
20 40
*/