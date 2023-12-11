/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int dp[111][111];
int p[maxn];
int n,m,len;
int ans=0;
int mull(int a,int b){
	int qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;
}
int f(int x){
	int cnt=0;while(x){cnt++;x/=2;}return cnt;
}
void solve()
{
	cin>>n>>m;
	if(n==1&&m==1){
		cout<<1<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if((1ll<<i-1)>m){
			cout<<0<<endl;
			return ;
		}
	}
	len=f(m);
	for(int i=1;i<=len;i++)
	{
		int x=(1ll<<i-1);
		int y=min(m,(1ll<<i)-1);
		int z=(y-x+1)%mod;
		p[i]=z;
		// cout<<p[i]<<" ";
	}
	// cout<<endl;
	for(int i=1;i<=len;i++)
		dp[1][i]=p[i];
	// for(int i=1;i<=n;i++)
	// 	dp[i][0]=1;

	for(int i=2;i<=n;i++)
	{
		for(int k=1;k<=len;k++)
		{
			for(int j=0;j<k;j++)
			{
				dp[i][k]+=dp[i-1][j]*p[k];
				dp[i][k]%=mod;
			}
		}
	}

	for(int i=n;i<=len;i++)
		ans=(ans+dp[n][i])%mod;
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
01  10

7


*/