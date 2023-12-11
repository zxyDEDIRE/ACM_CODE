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
const int N=3e3+100;
bool vis[N][N];
int dp[N][N];
pii last[N][N];
string a,b;
int n,m;
void solve()
{
	cin>>a>>b;
	a = " "+a;
	b = " "+b;
	n=a.size()-1;
	m=b.size()-1;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i]==b[j]){
				dp[i][j]=dp[i-1][j-1]+1;
				vis[i][j]=1;
				last[i][j]={i-1,j-1};
			}
			dp[i][j]=max({dp[i-1][j-1],dp[i][j],dp[i][j-1],dp[i-1][j]});
			if(dp[i][j]==dp[i-1][j-1])
				last[i][j]=last[i-1][j-1];
			if(dp[i][j]==dp[i][j-1])
				last[i][j]=last[i][j-1];
			if(dp[i][j]==dp[i-1][j])
				last[i][j]=last[i-1][j];
		}
	}
	// cout<<dp[n][m]<<endl;
	vector<char>v;
	pii now = {n,m};

	while(now.first!=0&&now.second!=0)
	{
		now = last[now.first][now.second];
		if(vis[now.first+1][now.second+1]){
			v.push_back(a[now.first+1]);
			// cout<<a[now.first+1]<<endl;
		}
	}
	reverse(v.begin(),v.end());
	for(auto i:v)
		cout<<i;
	cout<<endl;
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