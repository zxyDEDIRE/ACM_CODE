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
ll p[maxn];
int n,m;
bool check(ll mid)
{
	int x=1;
	int y=upper_bound(p+1,p+1+m,p[x]+mid*2)-p;
	if(y==m+1)return 1;
	int z=upper_bound(p+1,p+1+m,p[y]+mid*2)-p;
	if(z==m+1)return 1;
	int q=upper_bound(p+1,p+1+m,p[z]+mid*2)-p;
	if(q==m+1)return 1;

	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n);
	m=unique(p+1,p+1+n)-p-1;
	ll l=0,r=2e9,ans=r;
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