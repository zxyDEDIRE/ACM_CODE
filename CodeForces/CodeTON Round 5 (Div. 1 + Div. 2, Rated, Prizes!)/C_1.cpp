/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int dp[maxn][2];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)v[i].clear(),dp[i][0]=dp[i][1]=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],v[p[i]].push_back(i);
	for(int i=1;i<=n;i++)
	{
		int fl=upper_bound(v[p[i]].begin(),v[p[i]].end(),i)-v[p[i]].begin();

		dp[i][1]=max(dp[i][1],dp[i-1][0]);
		dp[i][1]=max(dp[i][1],dp[i-1][1]);

		if(fl!=v[p[i]].size()){
			fl=v[p[i]][fl];
			dp[fl][0]=max(dp[fl][0],dp[i][0]+fl-i);
			dp[fl][0]=max(dp[fl][0],dp[i][1]+fl-i+1);			
		}
		
	}
	cout<<max(dp[n][0],dp[n][1])<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3 1 1 2 2 1 
i+len
1
8
3 2 3 3 1 4 5 2


*/