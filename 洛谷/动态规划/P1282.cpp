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
int dp[1011][6011];
int n,sum,sum_ma;
void solve()
{
	cin>>n;
	memset(dp,INF,sizeof(dp));
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		for(int j=sum;j>=0;j--)
		{
			dp[i][j+x]=min(dp[i][j+x],dp[i-1][j]);
			dp[i][j+y]=min(dp[i][j+y],dp[i-1][j]+1);
		}
		sum+=x+y;
	}
	int mi=INF,fl=0;
	for(int i=0;i<=sum;i++)
	{
		if(dp[n][i]==INF)continue;
		int x=abs(i-(sum-i));
		if(x<mi)mi=x,fl=dp[n][i];
		else if(x==mi)fl=min(fl,dp[n][i]);
	}
	cout<<fl<<endl;
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