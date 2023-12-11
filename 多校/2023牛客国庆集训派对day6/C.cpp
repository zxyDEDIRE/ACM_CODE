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
const int N=222;
long long pre[N][N];
int mp[N][N];
int n,m;
void solve()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			scanf("%d",&mp[i][j]);
			pre[i][j]=mp[i][j];
		}
	for(int i=2;i<=n;i++)
		for(int j=1;j<=m;j++)
			pre[i][j]+=pre[i-1][j];
	for(int i=1;i<=n;i++)
		for(int j=2;j<=m;j++)
			mp[i][j]+=mp[i][j-1],pre[i][j]+=pre[i][j-1];
	double ans=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=j;k<=m;k++)
			{
				double p=pre[i][k]-pre[i][j-1];
				double s=mp[i][k]-mp[i][j-1];
				ans=max(ans,1.0*p/s);
			}
		}
	}
	printf("%.8f\n",ans);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
5e4*200*200
1e7
*/