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
const int maxn=5e3+100;
int dp[maxn][maxn];
ll pre[maxn];
ll a[maxn];
ll b[maxn];
int n,m;
int R(int r,ll w)
{
	int fl=lower_bound(pre+1,pre+1+n,pre[r]-w)-pre;
	return fl;
}
int L(int l,ll w)
{
	int fl=lower_bound(pre+1,pre+1+n,pre[l-1]+w)-pre;
	if(pre[fl]<=pre[l-1]+w)fl++;
	return fl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		pre[i]=pre[i-1]+a[i];
	}
	for(int i=1;i<=m;i++)
		cin>>b[i];
	for(int i=0;i<=m+1;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=INF;
	dp[m+1][1]=n;
	for(int i=m;i>=1;i--)
	{
		for(int l=1;l<=n;l++)
		{
			int r=dp[i+1][l];
			if(r==INF)continue;
			int _r=R(r,b[i]);
			int _l=L(l,b[i]);

			
			dp[i][l]=min({dp[i][l], dp[i+1][l],_r});
			dp[i][_l]=min({dp[i][_l], dp[i+1][_l],r});
			// if(i==1&&l==3)
			// {
			// 	cout<<l<<" "<<_l<<endl;
			// 	cout<<r<<" "<<_r<<endl;
			// 	cout<<dp[i][_l]<<" "<<dp[1][4]<<endl;
			// 	cout<<i<<endl;
			// 	cout<<endl;
			// }
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<"i:"<<i<<" "<<dp[2][i]<<endl;
	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<"i:"<<i<<" "<<dp[1][i]<<endl;
	// cout<<"Fuck "<<dp[1][4]<<endl;
	for(int i=1;i<=n;i++)
		if(dp[1][i]<=i){
			cout<<"Yes\n";
			return ;
		}
	cout<<"No\n";
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

7 4
1 2 3 4 5 6 7
1 2 3 4 3 2 1
3 3 3 3

4:
1--5
3--7
3:
1--4
3--5
4--7
2:
3--4

*/