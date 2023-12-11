#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
pp(7) p[1111];
int w[1111];
int ans=0;
int n,m,k;
/*
0 1 2  3 4 5 6
i j op a b d v
*/
void dfs(int x)
{
	if(x>n)
	{
		int now=0;
		for(int i=1;i<=m;i++)
		{
			auto a=p[i];
			if(a[2]==0)
			{
				if(a[3]*w[a[0]]+a[4]*w[a[1]]<=a[5])
					now+=a[6];
			}
			else
			{
				if(a[3]*w[a[0]]+a[4]*w[a[1]]>=a[5])
					now+=a[6];
			}
		}
		ans=max(ans,now);
		return ;
	}
	for(int i=0;i<=k;i++)
	{
		w[x]=i;
		dfs(x+1);
	}
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++)
		for(int j=0;j<7;j++)
			cin>>p[i][j];
	dfs(1);
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