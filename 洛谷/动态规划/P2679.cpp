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
int dp[203][203];
char a[maxn];
char b[maxn];
int n,m,t;
void solve()
{
	cin>>n>>m>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i],dp[0][0]=1;
	for(int j=1;j<=m;j++)
		cin>>b[j];
	dp[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=1;k<=t;k++)
			{
				// dp[j][k]+=dp[j][k];/
				int len=0;
				while(i-len>=1&&j-len>=1&&a[i-len]==b[j-len])
				{
					dp[j][k]+=dp[j-1-len][k-1];
					dp[j][k]%=INF;
					len++;
				}
			}
		}
	}
	cout<<dp[m][t]<<endl;
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