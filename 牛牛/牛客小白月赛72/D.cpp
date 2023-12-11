/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
const int N=1e3+10;
ll dp_a[N][N];
ll dp_b[N][N];
ll mp[N][N];
pii p[111];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			dp_a[i][j]=dp_b[i][j]=-1e10;
	dp_a[1][1]=0;
	dp_b[n][m]=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(i-1>=1)dp_a[i][j]=max(dp_a[i][j],dp_a[i-1][j]);
			if(j-1>=1)dp_a[i][j]=max(dp_a[i][j],dp_a[i][j-1]);
			dp_a[i][j]+=mp[i][j];
		}
	for(int i=n;i>=1;i--)
		for(int j=m;j>=1;j--){
			if(i+1<=n)dp_b[i][j]=max(dp_b[i][j],dp_b[i+1][j]);
			if(j+1<=m)dp_b[i][j]=max(dp_b[i][j],dp_b[i][j+1]);
			dp_b[i][j]+=mp[i][j];
		}
	int q;
	cin>>q;
	while(q--)
	{
		int k;
		cin>>k;
		ll ans=dp_a[n][m];
		for(int i=1;i<=k;i++)
			cin>>p[i].first>>p[i].second;
		for(int i=1;i<=k;i++)
			for(int j=1;j<=k;j++)
				if(i!=j){
					ans=max(ans,dp_a[p[i].first][p[i].second]+dp_b[p[j].first][p[j].second]);
				}
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
1 2 -1
-1 -1 -1
-1 -1 1
1
2
1 2
3 3

*/