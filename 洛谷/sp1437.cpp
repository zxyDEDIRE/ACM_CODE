/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int dep[maxn];
int n,s,t,ma;
void dfs1(int x,int fa)
{
	if(dep[x]>ma)
	{
		ma=dep[x];
		s=x;
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs1(y,x);
	}
}
void dfs2(int x,int fa)
{
	if(dep[x]>ma)
	{
		ma=dep[x];
		s=x;
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs2(y,x);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	ma=0;
	memset(dep+1,0,sizeof(int)*n);
	dfs2(s,0);
	cout<<ma<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}