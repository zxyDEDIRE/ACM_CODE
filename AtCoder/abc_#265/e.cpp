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
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=333;
ll dp[maxn][maxn][maxn];
map<pii,bool>mp;
ll n,m,a,b,c,d,e,f;
ll ans=0;
void solve()
{
	cin>>n>>m>>a>>b>>c>>d>>e>>f;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		mp[{x,y}]=1;
	}
	dp[0][0][0]=1;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;i+j<=n;j++)
		{
			for(int k=0;i+j+k<=n;k++)
			{
				ll x=a*i+c*j+e*k;
				ll y=b*i+d*j+f*k;
				if(mp[{x,y}])continue;
				if(i>=1)dp[i][j][k]+=dp[i-1][j][k];dp[i][j][k]%=mod;
				if(j>=1)dp[i][j][k]+=dp[i][j-1][k];dp[i][j][k]%=mod;
				if(k>=1)dp[i][j][k]+=dp[i][j][k-1];dp[i][j][k]%=mod;
				
				if(i+j+k==n)ans=(ans+dp[i][j][k])%mod;
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}