#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353;
const int maxn=500+10;
ll mp[maxn][maxn];
int dp[500][500][1000];
ll n,m,p,q;
void solve()
{
	cin>>n>>m>>p>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];


	if(mp[1][1]==1)dp[1][1][1]=1;
	else dp[1][1][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=0;k<=i+j-1;k++)
			{
				if(mp[i][j]==1){
					if(k>0)
					dp[i][j][k]+=dp[i-1][j][k-1]+dp[i][j-1][k-1];
				}
				else 
					dp[i][j][k]+=dp[i-1][j][k]+dp[i][j-1][k];
				cout<<dp[i][j][k];
			}
			cout<<" ";
		}
		cout<<endl;
	}
	ll ans=0;
	cout<<endl;
	for(int i=q;i<=(n+m-1-p);i++)
		ans+=dp[n][m][i];
	cout<<ans<<endl;
}
int main(){
	int __;
	__=1;
	while(__--)solve();
}
/*
105 38
2+
*/