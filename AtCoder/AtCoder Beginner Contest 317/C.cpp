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
int n,m,ma=0;
void dfs(int x,int w)
{
	ma=max(ma,w);
	for(auto [y,c]:v[x])
	{
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,w+c);
		vis[y]=0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	for(int i=1;i<=n;i++)
		v[0].push_back({i,0});
	dfs(0,0);
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}