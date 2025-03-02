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
const int N=1e4;
vector<pii>pa,pb;
int dp[N];
int n,w;
int DP(vector<pii>&p)
{
	int len=p.size();
	for(int j=0;j<=w;j++)
		dp[j]=0;
	for(int i=1;i<=len;i++)
	{
		for(int j=0;j<=w;j++)
		{
			auto [c,w]=p[i-1];
			if(j>=c)
				dp[j-c]=max(dp[j-c],dp[j]+w);
		}
	}
	int ma=0;
	for(int i=0;i<=w;i++)
		ma=max(ma,dp[i]);
	return ma;
}
void solve()
{
	cin>>n>>w;
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		if(a==0)pa.push_back({b,c});
		else pb.push_back({b,c});
	}
	int ans_1=DP(pa);
	int ans_2=DP(pb);
	if(ans_1>=ans_2)cout<<ans_1<<" 0\n";
	else cout<<ans_2<<" 1\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}