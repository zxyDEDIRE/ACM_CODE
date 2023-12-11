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
const int maxn=2e5+6000;
bitset<maxn>dp,ans;
ll p[maxn],pre[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	pre[0]=1;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+p[i]-1;
	dp[1]=1;
	for(int i=1;i<=n;i++)
	{
		dp|=(dp<<p[i]);
		ans[i]=dp[i];dp[i]=0;
	}
	for(int i=n+1;i<=n*2;i++)
		ans[i]=dp[i],pre[i]=pre[i-1]-1;
	ll ma=0;
	for(int i=1;i<=n*2;i++)
		if(ans[i])ma=max(ma,pre[i]);
	cout<<ma<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}