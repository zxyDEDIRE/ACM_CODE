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
bool p[55][55][60];
int dis[55][55];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
			dis[i][j]=1e6;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		dis[x][y]=1;
		p[x][y][0]=1;
	}
	for(int P=1;P<60;P++)
	{
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(p[i][k][P-1]&&p[k][j][P-1])
					{
						p[i][j][P]=1;
						dis[i][j]=1;
					}
				}
			}
		}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	cout<<dis[1][n]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}