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
const int maxn=1e6;
vector<ll>v[maxn];
ll n,k,ans;
void dfs(int x,ll sum)
{
	if(x==n+1)
	{
		if(sum==k)ans++;
		return ;
	}
	for(auto i:v[x])
	{
		if(sum*i>k)continue;
		else
		{
			dfs(x+1,sum*i);
		}

	}
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int m;cin>>m;
		for(int j=1;j<=m;j++)
		{
			ll x;cin>>x;
			v[i].push_back(x);
		}
	}
	dfs(1,1);
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}