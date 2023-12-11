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
vector<int>v[maxn];
int siz[maxn];
ll dis[maxn];
ll dp[maxn];
int n,m;
void dfs(int x,int fa=0)
{
	siz[x]=1;
	dis[x]=dis[fa]+1;
	for(auto y:v[x]){
		if(y!=fa){
			dfs(y,x);
			siz[x]+=siz[y];
		}
	}
}
void DP(int x,int fa=0)
{
	for(auto y:v[x])
		if(y!=fa){
			dp[y]=dp[x]-siz[y]+(n-siz[y]);
			DP(y,x);
		}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	for(int i=1;i<=n;i++){
		dp[1]+=dis[i];
	}
	DP(1);
	ll ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,dp[i]);
	for(int i=1;i<=n;i++)
		if(dp[i]==ma){
			cout<<i<<endl;
			return ;
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