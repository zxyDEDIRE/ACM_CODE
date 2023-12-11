#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn],G[maxn];
int dis[maxn];
int n;
void dfs(int x,int fa)
{
	dis[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		v[x].push_back(y);
		dis[x]+=dis[y];
	}
}
void dfs1(int x)
{
	
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)v[i].clear(),G[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,1);
	dfs1(1);
}
int main()
{
	solve();
}