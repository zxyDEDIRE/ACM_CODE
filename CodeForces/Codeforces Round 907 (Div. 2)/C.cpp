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
ll pre[maxn],suf[maxn];
ll a[maxn];
int n;
bool check(ll mid)
{
	ll s=0,t=mid;
	if(mid>=pre[n])return 1;
	for(int i=1;i<=n;i++)
	{
		t=mid-i;
		s=t+t-suf[i+1];
		if(suf[i+1]<=t && pre[i]<=s)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,[&](int a,int b){
		return a>b;
	});
	pre[0]=suf[n+1]=0;
	for(int i=1;i<=n;i++)
		pre[i]=pre[i-1]+a[i];
	for(int i=n;i>=1;i--)
		suf[i]=suf[i+1]+a[i];
	ll l=1,r=pre[n],ans=r;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	while(ans&&check(ans-1))ans--;
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
/*

*/