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
ll sum[maxn];
ll dp[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	if(n==1)
	{
		cout<<2*m+1<<endl;
		return ;
	}
	int mid=m+1;
	for(int i=-m;i<=m;i++)
	{
		for(int j=-m;j<=m;j++)
		{
			if(i+j<0)continue;
			dp[min(j,i+j)+mid]++;
		}
	}
	for(int i=1;i<=m*2+1;i++)
		sum[i]=(sum[i-1]+dp[i])%mod;
	// cout<<sum[m*2+1]<<endl;
	for(int i=3;i<=n;i++)
	{
		// cout<<endl;
		// for(int j=1;j<=m*2+1;j++)
			// cout<<"sum "<<j-mid<<" "<<sum[j]<<" "<<sum[j]-sum[j-1]<<endl;
		for(int j=1;j<=m*2+1;j++)
		{
			int now=j-mid;
			if(now<0)
			{
				int to=-now+mid;
				// cout<<now<<" "<<-now<<" "<<sum[m*2+1]-sum[to-1]<<endl;
				dp[j]=((sum[m*2+1]-sum[to-1])%mod+mod)%mod;
			}
			else
			{
				int to=-(m-now)+mid;
				// cout<<now<<" "<<-(m-now)<<" "<<sum[m*2+1]-sum[to-1]<<endl;
				dp[j]=((sum[m*2+1]-sum[to-1])%mod+mod)%mod;
			}
		}
		for(int j=1;j<=m*2+1;j++)
			sum[j]=(sum[j-1]+dp[j])%mod;
	}
	cout<<sum[m*2+1]<<endl;
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

*/