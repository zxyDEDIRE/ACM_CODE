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
int f[maxn][23];
int h[maxn][23];
int dep[maxn];
int a[maxn];
int n;
void dfs(int x,int fa=0)
{
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	h[x][0]=a[x];
	for(int i=1;i<=22;i++)
	{
		f[x][i]=f[f[x][i-1]][i-1];
		h[i][i]=f[x][i-1]|f[f[x][i-1]][i-1];
	}

	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for (int j = 0, D = dep[x] - dep[y]; D; ++j, D >>= 1)
		if (D & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 20; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y,ma=0;
		cin>>x>>y;
		int _lca=LCA(x,y);
		int l=0,r=dep[x]+dep[y]-dep[_lca]*2;
		

	}

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