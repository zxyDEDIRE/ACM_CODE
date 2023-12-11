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
const int maxn=10011;
bitset<maxn>vis;
vector<int>v[maxn];
int f[maxn][15];
int dp[maxn];
int n,m;
void dfs(int x,int fa)
{
	if(vis[x])return ;
	vis[x]=1;
	f[x][0]=fa;
	for(int i=1;i<15;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:v[x])
		dfs(y,x);
	if(x==n)dp[x]=0;
	for(int i=0;i<15;i++)
		dp[f[x][i]]=min(dp[f[x][i]],dp[x]+1);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		dp[i]=INF;
	dfs(1,0);
	cout<<dp[1]<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
7 8
1 6
5 1
6 4
4 5
5 2
3 7
7 5
2 3
*/