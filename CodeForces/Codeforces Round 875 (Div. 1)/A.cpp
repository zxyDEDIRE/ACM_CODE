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
vector<pii>v[maxn];
int dp[maxn];
int n;
void dfs(int x,int fa,int c=0)
{
	int flag=0;
	for(auto [y,w]:v[x])
	{
		if(y==fa)continue;
		if(w<c)dp[y]=dp[x]+1;
		else dp[y]=dp[x];
		dfs(y,x,w);
	}
	dp[x]+=flag;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		dp[i]=0;v[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}
	dp[1]=1;
	dfs(1,0);
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,dp[i]);
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
7
5 3
2 3
1 2
6 4
6 7
4 1
*/