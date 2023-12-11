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
bitset<maxn>vis;
int dp[maxn];
int Mi[maxn];
int p[maxn];
int n,m,ma;
void dfs(int x,int mi,int fa)
{
	int flag=1;

	mi=min(mi,p[x]);
	if(Mi[x]>mi)Mi[x]=mi,flag=0;

	int ma=max(dp[fa],p[x]-mi);
	if(ma>dp[x])dp[x]=ma,flag=0;

	if(flag)return ;
	for(int i=0;i<v[x].size();i++)
	{
		dfs(v[x][i],mi,x);
	}

}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i],Mi[i]=0x3f3f3f3f;
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(z==1)
		{
			v[x].push_back(y);
		}
		else
		{
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
	dfs(1,0x3f3f3f3f,1);
	cout<<dp[n]<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}