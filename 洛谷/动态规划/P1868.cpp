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
const int maxn=3e6+10;
vector<int>v[maxn];
int dp[maxn];
int n,len;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
		len=max(len,y);
	}
	for(int i=1;i<=len;i++)
	{
		dp[i]=dp[i-1];
		for(auto j:v[i])
			dp[i]=max(dp[i],dp[j-1]+i-j+1);
	}
	cout<<dp[len]<<en
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