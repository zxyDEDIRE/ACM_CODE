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
ll a[maxn],b[maxn];
ll n,m,u;
bool check(int mid)
{
	for(int l=1;l+mid-1<=n;l++)
	{
		ll x=0,y=0,fl=1;
		for(int i=l;i<=l+mid-1;i++)
		{
			x+=a[i];
			y+=b[i];
			if(y>u)fl=0;
		}
		if(x>m)fl=0;
		if(fl)return 1;
	}
	return 0;
}
void solve()
{
	cin>>n>>m>>u;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>b[i];
	int l=0,r=n,ans=0;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(ans<n&&check(ans+1))ans++;
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}