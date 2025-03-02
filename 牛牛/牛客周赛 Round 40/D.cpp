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
const int N=444;
int dp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int t,p,x,y,a,l=0;
		cin>>t>>p>>x>>y>>a;
		vector<pii>v;
		while(l<=a&&p<=m)
		{
			v.push_back({t,p});
			t+=y;
			p+=x;
			l++;
		}
		for(auto [x,y]:v)
		{
			for(int k=m;k>=0;k--)
				if(k>=y){
					dp[i][k]=max(dp[i][k],dp[i-1][k-y]+x);
				}
		}
		for(int k=m;k>=0;k--)
			dp[i][k]=max(dp[i][k],dp[i-1][k]);
	}
	cout<<dp[n][m]<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}