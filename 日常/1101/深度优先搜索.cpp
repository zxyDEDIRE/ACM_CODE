#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+100;
int mp[111][111];
bool vis[111];
int n,m;
// n个点 m条边

void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;

	for(int i=1;i<=n;i++)
		if(!vis[i] && mp[x][i])
			dfs(i);
}
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		mp[x][y]=1;
	}

	dfs(1);
}
signed main(){
		solve();
	return 0;
}