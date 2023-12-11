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
const int mod=19650827;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=1111;
int dp[N][N][2];
int p[N];
int n;
int dfs(int l,int r,int fl,int w)
{
	if(dp[l][r][fl]!=-1)return dp[l][r][fl];
	if(l==r)
	{
		if(fl==1&&w>p[l])return dp[l][r][fl]=1;
		if(fl==0&&w<p[l])return dp[l][r][fl]=1;
		return dp[l][r][fl]=0;
	}
	int ans=0;
	if(fl==0)
	{
		if(w<p[l])ans+=dfs(l+1,r,0,p[l]);
		if(w<p[r])ans+=dfs(l,r-1,1,p[r]);
		ans%=mod;
	}
	else if(fl=1)
	{
		if(w>p[l])ans+=dfs(l+1,r,0,p[l]);
		if(w>p[r])ans+=dfs(l,r-1,1,p[r]);
		ans%=mod;
	}
	// cout<<l<<" "<<r<<" "<<fl<<" "<<w<<" "<<ans<<endl;
	return dp[l][r][fl]=ans;
}
void solve()
{
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cout<<(dfs(2,n,0,p[1])+dfs(1,n-1,1,p[n]))%mod<<endl;
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