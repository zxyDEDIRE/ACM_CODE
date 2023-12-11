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
const int INF=1e18+7;
const int maxn=1e6+100;
ll dp[maxn];
ll p[maxn];
ll n,ans;
//x-3 x-2 x-1 x
int f(int x)
{
	return p[x]-p[x-2]+p[x-1]-p[x-3];
}
//x-5 x-4 x-3 x-2 x-1 x
//1 3
//4 6
//2 5
int h(int x)
{
	return p[x-3]-p[x-5]+p[x]-p[x-2]+p[x-1]-p[x-4];
}
void solve()
{
	cin>>n;
	ans=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],dp[i]=INF;
	sort(p+1,p+1+n);
	for(int i=1;i<=n;i+=2)
		ans+=p[i+1]-p[i];
	for(int i=4;i<=n;i+=2)
	{
		if(i>=4)
			dp[i]=min(dp[i],dp[i-4]+f(i));
		if(i>=6)
			dp[i]=min(dp[i],dp[i-6]+h(i));
	}
	cout<<ans<<endl;
	cout<<ans+dp[n]<<endl;
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
1 2 3 4 5 6
1 3 
4 6 
2 5

12
4 4 4 4 4 4 7 7 7 7 7 7
*/