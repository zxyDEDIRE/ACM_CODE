/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
int p[maxn];
int dp[10][10];
string str;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>str;
	str=" "+str;
	for(int i=1;i<=n;i++)
	{
		int x=(p[i]&1);
		int y=(str[i]=='R'?0:1);
		dp[x^1][y^1]=max(dp[x^1][y^1],dp[x][y]+p[i]);
	}
	cout<<max({dp[0][0],dp[0][1],dp[1][1],dp[1][0]})<<endl;
}
signed main(){
	cout<<(8|(-8))<<endl;
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		// solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
// 8421