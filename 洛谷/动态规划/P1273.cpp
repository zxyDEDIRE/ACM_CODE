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
vector<pii>v[maxn];
int dp[3011][3011];
vector<int>w[maxn];
int sum[maxn];
int p[maxn];
int n,m;
void dfs(int x)
{
	dp[x][0]=0;
	if(v[x].size()==0)
	{
		sum[x]+=p[x];
		dp[x][p[x]]=1;
	}
	for(auto [y,w]:v[x])
	{
		dfs(y);
		sum[x]+=sum[y];
		for(int i=sum[x];i>=0;i--)
		{
			if(dp[x][i]==-1)continue;
			for(int j=1;j<=sum[y];j++)
				if(dp[y][j]!=-1)
					dp[x][i+j-w]=max(dp[x][i+j-w],dp[x][i]+dp[y][j]);
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n-m;i++)
	{
		int k;cin>>k;
		while(k--)
		{
			int y,w;cin>>y>>w;
			v[i].push_back({y,w});
		}
	}
	for(int i=n-m+1;i<=n;i++)
		cin>>p[i];
	memset(dp,-1,sizeof(dp));
	dfs(1);
	// for(int i=1;i<=sum[5];i++)
	// 	cout<<dp[5][i]<<" ";cout<<endl;
	// for(int i=1;i<=sum[2];i++)
	// 	cout<<dp[2][i]<<" ";cout<<endl;
	// for(int i=0;i<=sum[1];i++)
	// 	cout<<dp[1][i]<<" ";cout<<endl;
	int ma=0;
	for(int i=0;i<=sum[1];i++)
		ma=max(ma,dp[1][i]);
	cout<<ma<<endl;
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
5 3
2 2 2 5 3
2 3 2 4 3
10 4 2
*/