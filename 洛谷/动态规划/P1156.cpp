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
struct node{
	int t,f,h;
}p[maxn];
int dp[111][3011];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].t>>p[i].f>>p[i].h;
	sort(p+1,p+1+m,[&](node a,node b){
		return a.t<b.t;
	});
	memset(dp,-1,sizeof(dp));
	dp[0][10]=0;
	for(int i=1;i<=m;i++)
	{
		int flag=0;
		int t=p[i].t,h=p[i].h,f=p[i].f;
		for(int j=t;j<=3011;j++)
		{
			if(dp[i-1][j]!=-1)
			{
				flag=1;
				dp[i][j]=max(dp[i][j],dp[i-1][j]+h);
				dp[i][j+f]=max(dp[i][j+f],dp[i-1][j]);
			}
			if(dp[i][j]>=n)
			{
				cout<<t<<endl;
				return ;
			}
		}
	}
	int sum=10;
	for(int i=1;i<=m;i++)
		if(p[i].t>sum){
			cout<<sum<<endl;
			return ;
		}
		else sum+=p[i].f;
	cout<<sum<<endl;
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