#include <bits/stdc++.h>
//#define int long long

#define endl '\n'
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int mod=998244353;
const int maxn=100005;

int n,cnt;
int sz[maxn];
vector<int> G[maxn];
void dfs(int now,int fa)
{
	sz[now]=1;
	for(auto i:G[now])
	{
		if(i==fa)
			continue;
		dfs(i,now);
		sz[now]+=sz[i];
		if(sz[i]%2==0&&(n-sz[i])%2==0)
			cnt++;
		if((n-sz[i])%2==0)
			cnt++;
	}
}
void solve()
{
	cnt=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++)
	{
		int u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout<<"ans "<<cnt<<endl;
	cout<<((1ll<<(cnt))-1+mod)%mod<<"\n";
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;
	cin>>__;
	while(__--)
		solve();
	return 0;
}