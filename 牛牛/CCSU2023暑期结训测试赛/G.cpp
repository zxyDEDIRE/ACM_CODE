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
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=444;
array<int,3>q[maxn];
bool vis[N][N];
ll dis[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		dis[x][y]=dis[y][x]=w;
		q[i]={x,y,w};
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(dis[i][j]>=dis[i][k]+dis[k][j])
				{
					dis[i][j]=dis[i][k]+dis[k][j];
					vis[i][j]=1;
				}
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=q[i];
		if(vis[x][y])ans++;
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}