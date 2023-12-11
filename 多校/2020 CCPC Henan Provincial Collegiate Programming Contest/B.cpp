/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e5+10;
int dp[maxn][333];
int p[maxn];
int d[maxn];
int n,m,ma;
void solve()
{
	cin>>n>>m;
	// for(int i=1;i<=n;i++)
		// cin>>p[i];
	for(int i=1;i<=n;i++)
		// cin>>d[i];
		d[i]=i;

	set<int>s;
	s.insert(m);
	for(int i=1;i<=n;i++)
	{
		for(auto j:s)
			s.insert((int)j/d[i]);
	}
	for(auto i:s)
		cout<<i<<" ";
	cout<<endl;
	cout<<s.size()<<endl;
	cout<<sqrt(m)<<endl;

	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=m;j>=0;j--)
	// 	{
	// 		dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
	// 		dp[i+1][j/d[i]]=max(dp[i+1][j/d[i]],dp[i][j]+j*p[i]);
	// 	}
	// }
	// int ma=0;
	// for(int i=0;i<=m;i++)
	// 	ma=max(ma,dp[n+1][i]);
	// cout<<ma<<endl;

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
1, 2, 3, 5
*/