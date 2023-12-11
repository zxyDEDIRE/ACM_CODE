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
int dp[maxn];
int f(int x)
{
	if(dp[x]!=0)return dp[x];
	for(int i=1;i<=sqrt(x);i++)
		if(x%i==0){
			if((x/i)!=i)dp[x]+=2;
			else dp[x]++;
		}
	return dp[x];
}
void solve()
{
	int ans=0,n;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x=i;
		int y=n-i;
		ans=ans+f(x)*f(y);
		// cout<<x<<" "<<f(x)<<endl;
		// cout<<y<<" "<<f(y)<<endl;
		// cout<<endl;
	}
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

*/