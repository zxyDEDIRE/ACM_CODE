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
int dp[maxn];
int p[maxn];
int a[maxn];
int n;
void solve()
{
	cin>>n;
	int fl=0;
	for(int i=0;i<n;i++)
		cin>>p[i];
	int ans=INF;

	dp[0]=-1;
	for(int j=1;j<=n;j++)
	{
		int tot=0;
		for(int i=0;i<n;i++)
		{
			if(p[i]>dp[tot])dp[++tot]=p[i];
			else
			{
				int fl=lower_bound(dp+1,dp+1+tot,p[i])-dp;
				dp[fl]=p[i];
			}
		}
		ans=min(ans,n-tot);
		for(int i=0;i<n;i++)
			a[i]=p[i];
		for(int i=0;i<n;i++)
			p[i]=a[(i+1)%(n)];
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
4 7 3 6 2 5 1 8
1 4 7 3 6 2 5 8
1 2 4 7 3 6 5 8
1 2 3 4 7 6 5 8
1 2 3 4 5 7 6 8
1 2 3 4 5 6 7 8

8
1 7 2 3 4 5 6 8
*/