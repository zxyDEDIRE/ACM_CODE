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
bool dp[maxn];
ll p[maxn];
ll w,f,sum;
int n;
bool check(int mid)
{
	ll a=w*mid;a=min(a,sum);
	ll b=f*mid;b=min(b,sum);
	if(a>b)swap(a,b);
	for(int i=1;i<=a;i++)dp[i]=0;
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a;j>=0;j--)
		{
			if(j>=p[i])dp[j]|=dp[j-p[i]];
			if(dp[j]&&b>=(sum-j))return 1;
		}
	}
	return 0;
}
void solve()
{
	cin>>w>>f>>n;
	sum=0;
	for(int i=1;i<=n;i++)
		cin>>p[i],sum+=p[i];
	int l=1,r=sum,ans=r;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans>1&&check(ans-1))ans--;
	cout<<ans<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}