/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
ll siz[maxn];
ll dp[maxn];
ll p[maxn];
ll n,mi=10e9;
void dfs(int x,int fa,int dep)
{
	siz[x]=p[x];
	dp[1]+=p[x]*dep;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x,dep+1);
		siz[x]+=siz[y];
	}
}
void dfs1(int x,int fa)
{
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dp[y]=dp[x]+siz[1]-siz[y]*2;
		dfs1(y,x);
	}
	mi=min(mi,dp[x]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int w,l,r;
		cin>>w>>l>>r;
		p[i]=w;
		if(l)v[i].push_back(l),v[l].push_back(i);
		if(r)v[i].push_back(r),v[r].push_back(i);
	}
	dfs(1,1,0);
	mi=dp[1];
	dfs1(1,1);
	cout<<mi<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}