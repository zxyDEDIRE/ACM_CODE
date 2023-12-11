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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int dp[207][407][407];
int p[207];
int d[207];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>p[i]>>d[i];
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int x=n*20;x>=0;x--)
			{
				for(int y=n*20;y>=0;y--)
				{
					if(x>=p[i]&&y>=p[i])
						dp[j][x][y]|=dp[j-1][x-p[i]][y-p[i]];
				}
			}
		}
	}
	for(int len=0;len<=n*20;len++)
	{
		for(int i=1;i+len-1<=n*20;i++)
		{
			if(dp[m][i][i+len-1]){
				cout<<len<<" "<<i<<" "<<i+len-1<<endl;
			}
		}
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