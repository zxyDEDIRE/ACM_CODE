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
ll n,ans=0;
void solve()
{
	cin>>n;
	ans=0;
	for(int t=n;t>=1;t--)
	{
		ll now=0,ma=0;
		for(ll i=1;i<t;i++)
			now+=i*i,ma=max(ma,i*i);
		for(ll i=t;i<=n;i++)
			now+=i*(n-i+t),ma=max(ma,i*(n-i+t));
		ans=max(ans,now-ma);
	}
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
1 2 3 4 5 6 7 8 9 10
285-81+90
204+90
294
*/