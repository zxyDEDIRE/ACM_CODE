#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n;
vector<int>tr[N];
long long ans[N];
long long res[N];
int a[N];
int mp[N];
void dfs(int now,long long sum,int tp)
{
	int v=a[now];
	ans[now]=sum-res[v]+tp;
	int tpp=res[v];
	res[v]=tp;
	mp[v]++;
	if(mp[v]==1) tp+=1;
	for(int u:tr[now])
	{
		dfs(u,ans[now],tp);
	}
	mp[v]--;
	res[v]=tpp;
}
void solve()
{
	for(int i=1;i<=n;i++) {
		tr[i].clear();
		ans[i]=0;
		res[i]=0;
		mp[i]=0;
	}
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		tr[x].push_back(i);
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	for(int i=2;i<=n;i++) cout<<ans[i]<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(cin>>n)
		solve();

	return 0;
}
/*
5
1 2 3 3
1 3 2 3 1
*/