/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
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
int dp[123][123][2];
int n,a,b,p,q;
int ksm(int b,int p){int r=1;b%=mod;while(p){if(p&1)r=(r*b)%mod;p>>=1;b=(b*b)%mod;}return r;}
void solve()
{
	cin>>n>>a>>b>>p>>q;
	dp[a][b][0]=1;
	for(int i=a;i<n;i++)
	{
		for(int j=b;j<n;j++)
		{
			for(int k=1;k<=p;k++){
				(dp[min(i+k,n)][j][1]+=dp[i][j][0]*ksm(p,mod-2)%mod)%=mod;
			}
			for(int k=1;k<=q;k++)
				(dp[i][min(j+k,n)][0]+=dp[i][j][1]*ksm(q,mod-2)%mod)%=mod;
		}
	}
	int sum=0;
	for(int i=n-1;i>=b;i--){
		sum+=dp[n][i][1];
		sum%=mod;
	}
	cout<<sum<<endl;
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