#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
vector<int>G[N];
typedef long long ll;
ll sz[N];
ll dfs(int x,int fa)
{
	sz[x]=1;
	ll ans1=0;
	for(auto i:G[x])
	{
		if(i==fa)continue;
		ans1=max(ans1,dfs(i,x));
		sz[x]+=sz[i];
	}
	return sz[x]+ans1;
}
void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		sz[i]=0,G[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	cout<<dfs(1,1)<<'\n';
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}