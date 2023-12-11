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
ll siz[maxn];
ll dp[maxn];
ll w[maxn];
int n;
void dfs1(int x,int fa)
{
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		dp[1]+=(w[x]^w[y])*siz[y];
	}
}
void dfs2(int x,int fa)
{
	if(x!=1)
	{
		dp[x]=(n-siz[x])*(w[x]^w[fa])+dp[fa]-siz[x]*(w[x]^w[fa]);
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs2(y,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i],dp[i]=0,v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		cout<<dp[i]<<" \n"[i==n];
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