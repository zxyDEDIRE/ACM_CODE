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
ll m[maxn][2];
ll q[maxn];
ll p[maxn];
ll n,ans,ma;
void dfs1(int x,int faa)
{
	for(auto y:v[x])
	{
		q[x]+=p[y];
		m[x][1]=max(m[x][1],p[y]);
		if(m[x][1]>m[x][0])swap(m[x][1],m[x][0]);
		if(y==faa)continue;
		dfs1(y,x);
	}
	ma=max(ma,m[x][1]*m[x][0]);
}
void dfs(int x,int faa)
{
	for(auto y:v[x])
	{
		ans+=(q[y]-p[x])*p[x];
		ans%=10007;
		if(y==faa)continue;
		dfs(y,x);
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
	for(int i=1;i<=n;i++)
		cin>>p[i];
	dfs1(1,0);
	dfs(1,0);
	cout<<ma<<" "<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}