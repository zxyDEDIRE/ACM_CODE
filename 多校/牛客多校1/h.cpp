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
const ll mod=998244353;
const int maxn=1e6;
ll a[maxn];
ll p[maxn];
ll n,m,k,ans;
void dfs(int x,int sum)
{
	//cout<<x<<" "<<sum<<endl;
	if(x==n+1)
	{
		ans++;
		return ;
	}
	for(int i=0;;i++)
	{
		if(i==p[x]&&p[x])continue;
		int t=a[x]*i;
		if(t>sum)break;
		dfs(x+1,sum-t);
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=k;i++)
	{
		ll x,y;
		cin>>x>>y;
		p[x]|=(1<<y);
	}
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
	cout<<endl;
	dfs(1,m);
	cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}