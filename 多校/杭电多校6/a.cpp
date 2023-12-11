/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn];
int dp[maxn][2];
int siz[maxn];
int n,ans;
int dfs(int x,int fa)
{
	int a=0,b=0,ma=0;
	siz[x]=1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		ma=max(ma,dfs(y,x));
		siz[x]+=siz[y];
		
	}
	return siz[x]+ma;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ans=0;
	cout<<dfs(1,1)<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}