/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int dp[maxn][2];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=0;i<=30;i++)
		dp[i][1]=1;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		
		for(int j=0;j<=30;j++)
		{
			if(x==1)	 dp[j][0]&=(y>>j&1),dp[j][1]&=(y>>j&1);
			else if(x==2)dp[j][0]|=(y>>j&1),dp[j][1]|=(y>>j&1);
			else if(x==3)dp[j][0]^=(y>>j&1),dp[j][1]^=(y>>j&1);
		}
		int num=0;
		for(int j=0;j<=30;j++)
		{
			int t=m>>j&1;
			num+=(dp[j][t]<<j);
		}
		cout<<num<<endl;
		m=num;
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}