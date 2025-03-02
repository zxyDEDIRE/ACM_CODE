#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int mod=998244353;
const int maxn=500+10;
int mp[maxn][maxn];
ll dp[2][500][1000];
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

				if(i==1&&j==1)continue;
				dp[i%2][j][k]=0;
				if(mp[i][j]==1){
					if(k>0)dp[i%2][j][k]+=dp[(i+1)%2][j][k-1]+dp[(i)%2][j-1][k-1];
				}
				else 
					dp[i%2][j][k]+=dp[(i+1)%2][j][k]+dp[(i)%2][j-1][k];
				dp[i%2][j][k]%=mod;
			}
		}
	}
	ll ans=0;
	for(int i=q;i<=(n+m-1-p);i++)
		ans+=dp[n%2][m][i],ans%=mod;
	cout<<ans<<endl;
}
int main(){
	int __;
	__=1;
	while(__--)solve();
}
/*
6 4 3 5
0 0 1 1 
0 1 0 1
1 1 0 0
0 1 0 1
0 1 0 1
1 1 1 1

*/