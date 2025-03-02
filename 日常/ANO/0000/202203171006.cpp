#include<bits/stdc++.h>
using namespace std;
const int maxn=300050;
int n,x,cnt[maxn]={0};
bool vis[maxn];
vector<int> ans;
vector<int> G[maxn];
void dfs(int k)
{
	if(x<=0) return;
	x--;
	ans.push_back(k);
	for(auto i:G[k])
	{
		if(vis[i])
			continue;
		vis[i]=1;
		dfs(i);
	}
}
int main()
{
	cin>>n>>x;
	if(n==1&&x==1)
	{
		return 0;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		cnt[u]++;
		cnt[v]++;
	}
	memset(vis,0,sizeof vis);
	for(int i=1;i<=n;i++)
	{
		if(cnt[i]==1)
		{
			vis[i]=1;
			dfs(i);
			break;
		}
	}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++)
		if(i!=ans.size()-1)cout<<ans[i]<<" ";
		else cout<<ans[i];
	return 0;
}