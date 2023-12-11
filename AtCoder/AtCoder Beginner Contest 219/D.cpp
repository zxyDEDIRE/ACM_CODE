/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
const int N=1011;
int a[N],b[N];
int dp[N][N];
int n,X,Y;
void solve()
{
	cin>>n>>X>>Y;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
	for(int i=0;i<=1000;i++)
		for(int j=0;j<=1000;j++)
			dp[i][j]=INF;
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int x=300;x>=0;x--)
		{
			for(int y=300;y>=0;y--)
			{
				dp[x][y]=min(dp[x][y],dp[max(0,x-a[i])][max(0,y-b[i])]+1);
			}
		}
	}
	int mi=INF;
	for(int x=X;x<=1000;x++)
		for(int y=Y;y<=1000;y++)
			mi=min(mi,dp[x][y]);
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
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