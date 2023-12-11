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
ll p[maxn];
ll a[maxn];
ll n,m;
bool check(ll mid)
{
	for(int i=1;i<=n;i++)
		a[i]=(mid+p[i]-1)/p[i];
	__int128 cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(i==n&&a[i]<=0){
			break;
		}
		cnt++,a[i]--;
		if(cnt>m)return 0;
		if(a[i]<=0)continue;
		cnt+=a[i]*2;
		if(cnt>m)return 0;
		a[i+1]-=a[i];
	}
	// cout<<mid<<" "<<(ll)cnt<<endl;
	return cnt<=m;
}
void solve()
{
	cin>>n>>m;
	// n=1e5;
	// m=1e12;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		// p[i]=1e5;
	}
	ll l=0,r=INF,ans=0;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans+1))ans++;
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
1
2 3
2 4

*/