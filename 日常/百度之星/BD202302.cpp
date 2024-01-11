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
const int N=18;
ll dp[20][20][32800];
ll p[N][N];
int n,m;
void solve()
{
	n=15;
	m=n*2-2;
	// cin>>n>>k;
	// for(int i=1;i<=n;i++)
		// for(int j=1;j<=n;j++)
			// cin>>p[i][j];
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(m,n-1);j++)
		{
			for(int k=0;k<=(1<<min(m-j,n-1));k++)
			{
				
			}
		}
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

*/
