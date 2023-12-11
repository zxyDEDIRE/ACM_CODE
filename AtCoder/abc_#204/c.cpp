/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis;
bitset<maxn>ok;
int n,m,ans,cnt;
void dfs(int x)
{
	if(ok[x])return ;
	if(vis[x])return ;
	vis[x]=1;
	cnt++;
	for(auto y:v[x])dfs(y);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		cnt=0;
		vis.reset();
		dfs(i);
		ans+=cnt;
	}
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}