#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e3+10;
int dp[maxn][maxn];
string s,t;
int main()
{	ios
	
	cin>>s;
	t=s;
	reverse(t.begin(),t.end());
	int n=t.size();
	t=" "+t;
	s=" "+s;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i]==t[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			else 
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<n-dp[n][n]<<endl;
	
}