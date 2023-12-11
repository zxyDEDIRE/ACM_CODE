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
int dp[111][111];
string str;
int n;
int dfs(int l,int r)
{
	if(l==r)return dp[l][r]=1;
	if(dp[l][r]!=-1)return dp[l][r];
	// cout<<l<<" "<<r<<" "<<dp[l][r]<<endl;
	dp[l][r]=INF;
	if(str[l]==str[r]){
		dp[l][r]=min(dfs(l+1,r),dfs(l,r-1));
	}
	else
	{
		for(int i=l;i<r;i++)
			dp[l][r]=min(dp[l][r],dfs(l,i)+dfs(i+1,r));
	}
	return dp[l][r];
}
void solve()
{
	cin>>str;
	n=str.size();
	str=" "+str;
	memset(dp,-1,sizeof(dp));
	cout<<dfs(1,n)<<endl;
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
DVSJROCQCVHTOJPUPKXP
*/