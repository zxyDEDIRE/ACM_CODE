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
int dp[10][600][600];
vector<int>v;
int n,k;
void dfs(int x,int num)
{
	if(x>=n){
		v.push_back(num);
		return ;
	}
	dfs(x+1,num);
	dfs(x+2,num+(1<<x));
}
void solve()
{
	cin>>n>>k;
	dfs(0,0);
	for(auto i:v)
		dp[1][i][__builtin_popcountll(i)]=1;
	for(int i=2;i<=n;i++)
	{
		for(auto x:v)
		{
			for(auto y:v)
			{
				if((x&y)||((x<<1)&y)||((x>>1)&y))continue;
				for(int j=k;j>=__builtin_popcountll(x);j--)
					dp[i][x][j]+=dp[i-1][y][j-__builtin_popcountll(x)];
			}
		}
	}
	int ans=0;
	for(auto i:v)
		ans+=dp[n][i][k];
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