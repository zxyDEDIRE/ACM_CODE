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
const int N=666;
int dp[N][N];
string str;
int n;
int dfs(int l,int r)
{
	if(l>r)return 0;
	if(l==r)return dp[l][r]=1;
	if(dp[l][r])return dp[l][r];
	dp[l][r]=1+dfs(l+1,r);
	for(int i=l+1;i<=r;i++)
	{
		if(str[l]==str[i]){
			dp[l][r]=min(dp[l][r],dfs(l+1,i)+dfs(i+1,r));
			// cout<<l<<" "<<r<<endl;
			// cout<<l+1<<" "<<i<<" "<<dfs(l+1,i)<<endl;
			// cout<<i+1<<" "<<r<<" "<<dfs(i+1,r)<<endl;
			// cout<<endl;
		}
	}
	return dp[l][r];
}
void solve()
{
	cin>>n>>str;
	str=" "+str;
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