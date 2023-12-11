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
ll sum[maxn];
ll s[maxn];
ll t[maxn];
ll p[maxn];
ll n,ans,flag;
void dfs(int x,ll num)
{
	if(s[x]==-1)p[x]=0;
	else p[x]=s[x]-num;

	if(p[x]<0)flag=1;

	ans+=p[x];

	ll mi=1e11;

	for(auto y:v[x])
	{
		dfs(y,num+p[x]);
		t[x]+=t[y];
		mi=min(mi,t[y]);
	}
	if(s[x]!=-1)mi=min(mi,p[x]);
	
	if(s[x]==-1)
	{
		ans-=mi*v[x].size();
		if(v[x].size())ans+=mi;	
		t[x]-=mi*v[x].size();
	}
	
	t[x]+=p[x];
	
	

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
		cin>>s[i];
	dfs(1,0);
	if(flag)cout<<-1<<endl;
	else cout<<ans<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
	return 0;
}