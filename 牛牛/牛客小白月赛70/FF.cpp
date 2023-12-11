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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int dp[maxn][55];
bitset<maxn>ned;
int siz[maxn];
int n,m,k;
void dfs(int x,int fa)
{
	int now[55];
	if(ned[x])dp[x][0]=0,siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		for(int i=0;i<=k;i++)
			now[i]=dp[x][i],dp[x][i]=INF;
		for(int i=0;i<=min(k,siz[x]);i++)
			for(int j=0;j<=min(k-i,siz[y]);j++){
				if(i+j<=k)
					dp[x][i+j]=min(dp[x][i+j],now[i]+dp[y][j]);
			}
		siz[x]+=siz[y];
	}
	for(int i=0;i<=k;i++)
		if(i<siz[x])dp[x][i]+=2;
	// cout<<x<<endl;
	// for(int i=0;i<=k;i++)
	// 	cout<<dp[x][i]<<" ";cout<<endl;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		ned[x]=1;
	}
	dfs(1,0);
	int ans=INF;
	for(int i=0;i<=k;i++)
		ans=min(ans,dp[1][i]);
	cout<<ans-2<<endl;
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
7 4
1 2
1 3
1 4
2 5
2 6
2 7
6
2 3 4 5 6 7



5 1
1 2
2 3
1 4
4 5
2
3 5
*/