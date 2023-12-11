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
const ll INF=1e18+7;
const int maxn=1e6+100;
ll dp[maxn];
ll w[maxn];
int n,d,p;
void solve()
{
	cin>>n>>d>>p;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n+d;i++)
		dp[i]=INF;
	sort(w+1,w+1+n);
	dp[0]=0;
	ll mi=INF;
	for(int i=1;i<=n+d;i++)
	{
		dp[i]=min(dp[i],dp[i-1]+w[i]);
		if(i-d>=0)
			dp[i]=min(dp[i],dp[i-d]+p);
		if(i>=n)mi=min(mi,dp[i]);
	}
	cout<<mi<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3 4 5 6 
*/