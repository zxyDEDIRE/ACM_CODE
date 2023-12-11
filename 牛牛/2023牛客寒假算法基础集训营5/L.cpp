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
const ll INF=1e18+7;
const int maxn=1e6+100;
const int N=1e5+10;
struct node{
	ll w,v;
}p[maxn];
ll dp[N];
ll n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].w>>p[i].v;
	for(int i=0;i<=n;i++)
		dp[i]=INF;
	// sort(p+1,p+1+m,[&](node a,node b){
	// 	if(a.v==b.v)return a.w<b.w;
	// 	return a.v>b.v;
	// });
	dp[n]=0;
	for(int j=n;j>=0;j--)
	{
		for(int i=1;i<=m;i++)
		{
			if(j>=p[i].v)
			{
				ll x=(j/p[i].v)*p[i].v;
				// if(dp[j]+p[i].w<dp[x])
				// {
				// 	cout<<j<<" "<<x<<" "<<p[i].v<<" "<<dp[j]+p[i].w<<endl;
				// }
				dp[x]=min(dp[x],dp[j]+p[i].w);
				
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(dp[i]!=INF){
			// cout<<i<<endl;
			cout<<dp[i]<<endl;
			return ;
		}
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
15 2
10 6
10 7

7  14
6  12
7  5
*/