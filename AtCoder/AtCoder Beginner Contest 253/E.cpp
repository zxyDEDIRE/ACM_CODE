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
void solve()
{
	int n,m,k;
	vector<int>p;
	vector<int>pre;

	cin>>n>>m>>k;
	pre.resize(m+1,0);
	p.resize(m+1,1);
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
			pre[j]=(pre[j-1]+p[j])%mod;
		vector<int>dp(m+1,0);
		for(int j=1;j<=m;j++)
		{
			if(k==0)dp[j]=pre[m];
			else
			{
				if(j>k)
					(dp[j]+=pre[j-k])%=mod;
				if(j+k<=m)
					(dp[j]+=(pre[m]-pre[j+k-1]+mod)%mod)%=mod;
			}
		}
		p=dp;
	}
	int ans=0;
	for(auto i:p)
		ans=(ans+i)%mod;
	cout<<ans<<endl;
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
/*
1 2 3 4
*/