/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int c[maxn];
int n,ans;
void dfs(int x,int t)
{
	for(auto y:v[x])
	{
		if(c[y]==t)
		{
			dfs(y,t);
		}
		else
		{
			ans++;
			dfs(y,c[y]);
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	ans=1;
	dfs(1,c[1]);
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}