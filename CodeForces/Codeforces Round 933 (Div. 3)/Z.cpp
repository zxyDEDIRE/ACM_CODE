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
vector<int>v[maxn];
int dep[maxn];
int siz[maxn];
int n;
int ans=
void dfs1(int x,int fa)
{
	siz[x]++;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dep[y]=dep[x]+1;
		dfs1(y,x);
		siz[x]+=siz[y];
	}
}
void solve()
{
	cin>>n;
	// for(int i=1;i<=n;i++)
	// {
	// 	int x,y,w;
	// 	cin>>x>>y>>w;
	// 	v[x].push_back({y,w});
	// 	v[y].push_back({x,w});
	
	// }

	int W=0;
	for(int i=1;i<=n;i++)
		W+=dep[i];

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