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
vector<int>v[maxn];
int dp[maxn][101];
int pre[maxn][101];
int dep[maxn];
int f[maxn][25];
int n,m;
void dfs1(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<=22;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	dp[x][0]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		for(int i=1;i<=100;i++)
			dp[x][i]+=dp[y][i-1];
	}
}
void dfs2(int x)
{
	int fa=f[x][0];
	if(fa){
		for(int i=100;i>=2;i--)
			dp[x][i]+=max(0,dp[fa][i-1]-dp[x][i-2]);
		dp[x][1]++;
	}
	for(int i=1;i<=n;i++)
		pre[x][i]+=dp[x][i];
	for(auto y:v[x])
		if(y!=f[x][0]){
			for(int i=1;i<=n;i++)
				pre[y][i]+=pre[x][i];
			dfs2(y);
		}
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for (int j = 0, d = dep[x] - dep[y]; d; ++j, d >>= 1)
		if (d & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 20; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1);
	for(int i=1;i<=n;i++)
	{
		cout<<"I "<<i<<" ";
		for(int j=1;j<=n;j++)
			cout<<dp[i][j]<<" ";cout<<endl;
	}
	while(m--)
	{
		int x,y,k;
		cin>>x>>y>>k;
		int lca=LCA(x,y);
		int tot=pre[x][k]+pre[y][k]-pre[f[lca][0]][k]*2-dp[lca][k];
		int dis=dep[x]+dep[y]-dep[lca]*2;
		int re=0;
		re+=2*max(0,dis+1-k*2);
		re+=min(dis+1,k*2);
		re*=2;
		cout<<"tot "<<tot<<endl;
		cout<<"lca "<<lca<<endl;
		cout<<pre[x][k]<<" "<<pre[y][k]<<" "<<f[lca][0]<<" "<<pre[f[lca][0]][k]<<endl;
		cout<<tot-re<<endl;
		cout<<endl;
	}
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
I 2 3 3 0 0 0 0 0
I 4 3 2 1 0 0 0 0
I 5 1 2 3 0 0 0 0
I 7 1 2 2 1 0 0 0
*/