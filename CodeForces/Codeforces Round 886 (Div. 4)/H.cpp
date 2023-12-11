#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<pii>v[maxn];
bitset<maxn>vis;
ll dis[maxn];
int n,m,flag;
void dfs(int x)
{
	if(flag)return ;
	vis[x]=1;
	for(auto [y,w]:v[x])
	{
		if(vis[y])
		{
			if(dis[y]!=dis[x]+w)
				flag=1;
		}
		else
		{
			dis[y]=dis[x]+w;
			dfs(y);
		}
	}
}
void solve()
{
	cin>>n>>m;
	vis.reset();flag=0;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,-w});
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	if(flag)cout<<"NO\n";
	else cout<<"YES\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}