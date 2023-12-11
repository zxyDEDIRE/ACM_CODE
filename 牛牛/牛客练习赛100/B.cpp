#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dp[maxn][4],a[4];
int p[maxn];
string str;
int n;
int main()
{	ios
	
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>str;
	str=" "+str;

	for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		dp[i][1]=dp[i-1][1];
		dp[i][2]=dp[i-1][2];
		dp[i][3]=dp[i-1][3];
		//r0 r1 b0 b1
		//0  1  2  3
		if(str[i]=='R'&&!(p[i]&1))//0
		{
			dp[i][0]-=a[0];
			a[0]=max(a[0],p[i]);
			dp[i][0]+=a[0];

			dp[i][0]=max(dp[i][0],dp[i-1][3]+p[i]);
		}
		else if(str[i]=='R'&&(p[i]&1))//1
		{
			dp[i][1]-=a[1];
			a[1]=max(a[1],p[i]);
			dp[i][1]+=a[1];

			dp[i][1]=max(dp[i][1],dp[i-1][2]+p[i]);
		}
		else if(str[i]=='B'&&!(p[i]&1))//2;
		{
			dp[i][2]-=a[2];
			a[2]=max(a[2],p[i]);
			dp[i][2]+=a[2];

			dp[i][2]=max(dp[i][2],dp[i-1][1]+p[i]);
		}
		else if(str[i]=='B'&&(p[i]&1))//3
		{
			dp[i][3]-=a[3];
			a[3]=max(a[3],p[i]);
			dp[i][3]+=a[3];

			dp[i][3]=max(dp[i][3],dp[i-1][0]+p[i]);
		}
	}
	int ma=0;
	for(int i=0;i<4;i++)
		ma=max(ma,dp[n][i]);
	cout<<ma<<endl;
	
}