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
int p[maxn];
int n,m,flag=0;
int find(int r){
	return p[r]=(p[r]==r)?p[r]:find(p[r]);
}
void dfs(int x,int fa,int top)
{
	if(vis[x])return ;
	vis[x]=1;
	if(v[x].size()!=2){
		flag=0;
		return ;
	}
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x,top);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)p[i]=i;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)p[fa]=fb;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(p[i]==i)
		{
			flag=1;
			dfs(i,i,i);
			if(flag)cnt++;
		}
	}
	cout<<cnt<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}