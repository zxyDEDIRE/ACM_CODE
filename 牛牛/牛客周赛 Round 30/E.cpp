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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
ll dp[maxn][2];
int n;
void dfs(int x,int fa=0)
{
	dp[x][0]=dp[x][1]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		dp[x][0]*=dp[y][1];
		dp[x][1]*=dp[y][1]+dp[y][0];
		dp[x][0]%=mod;
		dp[x][1]%=mod;
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
	cout<<(dp[1][1]+dp[1][0])%mod<<endl;
	// cout<<dp[2][0]<<" "<<dp[2][1]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1
|
2-3
|
4

4
1 2
2 3
2 4


100 101 110 111
011

*/