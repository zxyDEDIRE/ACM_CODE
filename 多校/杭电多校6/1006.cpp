#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7;
int n,ans;
int sz[maxn];
int son[maxn];
vector<int> G[maxn];
void dfs1(int now,int fa)
{
	sz[now]=1;
	for(auto i:G[now])
	{
		if(i==fa)
			continue;
		dfs1(i,now);
		sz[now]+=sz[i];
		if(!son[now]||sz[son[now]]<sz[i])
			son[now]=i;
	}
}
int dfs2(int now)
{
	ans+=sz[now];
	if(son[now])
		dfs2(son[now]);
}
void solve()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
	{
		G[i].clear();
		son[i]=0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1);
	cout<<ans<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;cin>>t;
	while(t--)
		solve();
	return 0;
}