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
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n;
	cin>>n;
	vector<vector<int>>dp(n+10,vector<int>(n+10,0));
	vector<vector<int>>mp(n+10,vector<int>(n+10,0));
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			cin>>mp[i][j];
	//dp[i][j] 第i个时有j个分隔
	dp[1][0]=1;
	for(int i=2;i<=n;i++)
	{
		int fl=0;
		if(mp[i][i]==2){
			cout<<0<<endl;
			return ;
		}
		for(int j=1;j<i;j++)
		{
			if(mp[j][i]!=1&&mp[1][i]!=1)fl=1;
			if(mp[j][i]==1)fl=0;
			for(int k=0;k<j;k++)
			{
				if(fl)
					dp[i][k+1]+=dp[j][k];
				dp[i][k]%=mod;
			}
		}
		for(int k=1;k<i;k++)
			if(mp[i-1][i]!=2)
				dp[i][k]+=dp[i-1][k],dp[i][k]%=mod;
			else break;
	}
	int ans=0;
	int ok=1;
	for(int i=1;i<=n;i++)
		if(mp[1][i]==2)ok=0;
	// if(ok)dp[n][0]=1;
	for(int i=0;i<=n;i++){
		ans+=dp[n][i];
		ans%=mod;
		// cout<<i<<" ";
		// cout<<dp[n][i]<<endl;
	}
	cout<<ans*2%mod<<endl;
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
0 0 1
*/
