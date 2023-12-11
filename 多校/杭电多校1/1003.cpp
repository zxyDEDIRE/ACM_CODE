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
const int maxn=(1<<11);
int c[maxn],v[maxn];
//bool dp[maxn][maxn];
bitset<maxn>dp[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	dp[0].reset();
	for(int i=1;i<=n;i++)
		cin>>c[i]>>v[i],dp[i].reset();
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=0;k<=(1<<10);k++)
			{
				if(j>=c[i])
				{
					int t=k^v[i];
					//dp[j][t]|=dp[j-c[i]][k];
					if(dp[j-c[i]][k])dp[j][t]=1;
				}
			}
		}
	}
	int ma=-1e9;
	for(int i=(1<<10);i>=0;i--)
	{
		if(dp[m][i]==1&&ma==-1e9){
			ma=i;
			break;
		}
	}
	if(ma==-1e9)cout<<-1<<endl;
	else cout<<ma<<endl;

}
int main()
{	
	int t=(1<<10);
	cout<<t<<endl;
	cout<<t*t*t<<endl;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}