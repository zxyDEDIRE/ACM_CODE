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
const int INF=1e18+7;
const int maxn=1e6+100;
int dp[7][7][7][7][7];
int p[111][10];
int n,k,t;
void solve()
{
	cin>>n>>k>>t;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			cin>>p[i][j];
	// cout<<p[1][0]<<" "<<p[1][1]<<" "<<p[1][2]<<" "<<p[1][3]<<endl;
	for(int a=t;a>=0;a--)
		{
			for(int b=t;b>=0;b--)
			{
				for(int c=t;c>=0;c--)
				{
					for(int d=t;d>=0;d--)
					{
						for(int e=t;e>=0;e--)
						{
							dp[a][b][c][d][e]=INF;
						}
					}
				}
			}
		}
	dp[0][0][0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int a=t;a>=0;a--)
		{
			for(int b=t;b>=0;b--)
			{
				for(int c=t;c>=0;c--)
				{
					for(int d=t;d>=0;d--)
					{
						for(int e=t;e>=0;e--)
						{
							dp[min(t,a+p[i][1])][min(t,b+p[i][2])][min(t,c+p[i][3])][min(t,d+p[i][4])][min(t,e+p[i][5])]=min(dp[min(t,a+p[i][1])][min(t,b+p[i][2])][min(t,c+p[i][3])][min(t,d+p[i][4])][min(t,e+p[i][5])],dp[a][b][c][d][e]+p[i][0]);
						}
					}
				}
			}
		}
	}
	// cout<<dp[3][0][2][0][0]<<endl;
	// cout<<dp[3][0][2][0][0]<<endl;
	// cout<<dp[5][4][2][0][0]<<endl;
	// cout<<dp[5][5][5][0][0]<<endl;
	vector<int>q(10,0);
	for(int i=1;i<=k;i++)
		q[i]=t;
	int ans=dp[q[1]][q[2]][q[3]][q[4]][q[5]];
	if(ans==INF)cout<<-1;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}