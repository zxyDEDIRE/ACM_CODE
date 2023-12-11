#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
pii p[maxn];
int dp[maxn];
int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b,y;
		cin>>a>>b>>y;
		int mid=(a+b+1)/2;
		p[i]={max(0ll,mid-a),y};
		m+=y;
	}
	for(int j=m;j>=1;j--)
		dp[j]=INF;
	dp[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=m;j>=1;j--)
		{
			if(j-p[i].second>=0)
			dp[j]=min(dp[j],dp[j-p[i].second]+p[i].first);
		}
	}
	int mi=INF;
	for(int i=m/2+1;i<=m;i++)
		mi=min(mi,dp[i]);

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