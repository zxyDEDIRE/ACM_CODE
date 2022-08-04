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
vector<int>v(maxn);
bitset<maxn>vis;
int num[maxn];
int p[maxn];
int n;
int dfs(int x)
{
	if(vis[x])return 0;
	if(p[x])return p[x];
	vis[x]=1;
	p[x]+=1+dfs(v[x]);
	return p[x];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		v[i]=x;
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		p[i]=dfs(i);
	}
	dfs(3);
	cout<<p[3]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}