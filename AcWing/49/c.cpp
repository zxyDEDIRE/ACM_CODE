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
const int mod=998244353;
const int maxn=1e6;
vector<int>v[maxn];
int vis[maxn];
int p[maxn];
ll ans,s,t,flag;
int n,m;
void dfs(int x,int fl,int fa)
{
	p[x]=fl;
	vis[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;

		if(vis[y])
		{
			if(p[x]==p[y])flag=1;
		}
		else
		{
			dfs(y,(fl+1)%2,x);
			if(fl%2==0)s*=2,t*=1;
			else s*=1,t*=2;
			s%=mod;
			t%=mod;
		}
	}
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		p[i]=0;
		vis[i]=0;
		ans=0;
	}
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=1;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		s=2,t=1,flag=0;
		dfs(i,1,-1);
		if(!flag)ans=(ans*(s+t)%mod)%mod;
		else
		{
			cout<<0<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
4 4
1 2
2 3
3 4
1 4
*/