#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0);cout.tie(0);
#define int long long
typedef long long ll;
typedef pair<int,int> P;
const int N=5e5+7;
const int mod=998244353;
int dep[N],fa[N];
int dp[N][3];
vector<int>v[N];
int n;
void dfs(int p,int fa)
{
	dp[p][1]=1;
	int sum=0;
	for(int di:v[p]){
		if(fa==di)continue;
		dfs(di,p);
		sum+=dp[di][0];
	}
	for(auto di:v[p]){
		if(fa==di)continue;
		dp[p][0]+=max({dp[di][0],dp[di][1],dp[di][2]});
		dp[p][1]=max({dp[p][1],sum+1});
		dp[p][2]=max(dp[p][2],dp[di][1]+1+sum-dp[di][0]);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)v[i].clear(),dp[i][0]=dp[i][1]=dp[i][2]=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	cout<<max({dp[1][0],dp[1][1],dp[1][2]})<<endl;
}
signed main()
{
	IOS
	 int size(512<<20);  // 512M
	 __asm__ ( "movq %0, %%rsp\n"::"r"((char*)malloc(size)+size));
	int __=1;
	cin>>__;
	while (__--)
		solve();
	exit(0);
	return 0;
}