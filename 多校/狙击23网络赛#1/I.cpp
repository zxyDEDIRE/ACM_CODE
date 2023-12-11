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
const int maxn=1e5+100;
vector<int>v[222];
int dp[maxn][222];
int p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		v[p[i]].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=200;j++)
		{
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
			if(j<=p[i])continue;
			int x=p[i];
			int y=j-x;
			int fl=lower_bound(v[y].begin(),v[y].end(),i)-v[y].begin();
			if(fl==0)continue;
			fl--;
			fl=v[y][fl]-1;
			dp[i][j]=max(dp[i][j],dp[fl][j]+2);
		}
	}
	int ma=0;
	for(int i=1;i<=200;i++)
		ma=max(ma,dp[n][i]);
	cout<<ma<<endl;
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
6
100 100 1 1 100 100
2
100 1

*/