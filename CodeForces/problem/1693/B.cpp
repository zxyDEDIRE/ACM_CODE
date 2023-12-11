#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
ll l[maxn];
ll r[maxn];
ll p[maxn];
int n,ans;
void init()
{
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		p[i]=0;
	}
	ans=0;
}
void dfs(int x)
{
	for(auto y:v[x])
	{
		dfs(y);
		p[x]+=r[y];
	}
	if(l[x]>p[x])ans++;
	else r[x]=min(r[x],p[x]);
}
void solve()
{
	cin>>n;
	init();
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>l[i]>>r[i];

	dfs(1);

	cout<<ans<<endl;


}
int main()
{	ios
	int __;cin>>__;
	while(__--)
		solve();
	
}