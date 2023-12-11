/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=5e3+100;
int dp[N][N];
int p[maxn];
int h[maxn];
int c[maxn];
int n,k;
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=k;i++)
		cin>>c[i];
	for(int i=1;i<=k;i++)
		cin>>h[i];
	for(int i=0;i<=k;i++)
		for(int j=0;j<=k;j++)
			dp[i][j]=1e18;
	for(int i=1;i<=k;i++)
		dp[p[1]][0]=c[p[1]];
	int last=p[1];
	int now;
	for(int i=2;i<=n;i++)
	{
		now=p[i];
		if(now==last)
		{
			for(int j=0;j<=k;j++)
					dp[now][j]=dp[last][j]+h[now];
		}
		else
		{
			int mi=1e18;
			for(int j=0;j<=k;j++)
					mi=min(mi,dp[last][j]);
			for(int j=0;j<=k;j++)
					dp[now][j]=dp[last][j]+c[now];

			dp[now][last]=mi+c[now];
			dp[now][last]=min(dp[now][last],dp[last][now]+h[now]);
		}
		last=now;
	}
	int mi=1e18;
	for(int i=0;i<=k;i++)
		mi=min(mi,dp[last][i]);
	cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}