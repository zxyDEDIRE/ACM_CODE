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
const int N=3333;
int dp[N][N][5];
char mp[N][N];
int n;
int f(int x,int y){
	int ans=0;
	for(int j=0;j<3;j++)
		ans+=dp[x][y][j];
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		// for(int j=1;j<=n;j++)
		// 	cout<<dp[i][j][0]<<" \n"[j==n];
		for(int j=1;j<=n;j++)
		{
			int now=f(i,j)+(mp[i][j]=='1');
			if(now&1)dp[i][j][4]=1,ans++;
			else dp[i][j][4]=0;
		} 
		for(int j=1;j<=n;j++)
			for(int k=0;k<=4;k++)
				dp[i+1][j][k]=0;
		for(int j=1;j<=n;j++)
		{
			dp[i+1][j][0]+=dp[i][j][0]+dp[i][j][4]+dp[i][j][1]+dp[i][j][2];
			dp[i+1][j-1][1]+=dp[i][j][1]+dp[i][j][4];
			dp[i+1][j+1][2]+=dp[i][j][2]+dp[i][j][4];
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
0*0*0*
111101
011110
000000
111010
001110
*/