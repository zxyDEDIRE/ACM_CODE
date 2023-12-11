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
const int N=1e3;
ll dp[N];
ll w[N];
ll v[N];
ll n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i]>>v[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=0;j--)
		{
			if(j>=w[i])
				dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	ll ma=dp[m];
	for(int x=1;x<=n;x++)
	{
		for(int i=0;i<=m;i++)
			dp[i]=0;
		for(int i=1;i<=n;i++)
		{
			if(i==x)continue;
			for(int j=m-w[x];j>=0;j--)
			{
				if(j>=w[i])
					dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
			}
		}
		ll ans=dp[m-w[x]]+v[x];
		if(ans<ma) cout<<ma-ans+1<<endl;
		else
		{
			for(int i=0;i<=m;i++)
				dp[i]=0;
			for(int i=1;i<=n;i++)
			{
				if(i==x)continue;
				for(int j=m;j>=0;j--)
				{
					if(j>=w[i])
						dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
				}
			}
			if(dp[m]==ans)cout<<1<<endl;
			else cout<<0<<endl;
		}
	}
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