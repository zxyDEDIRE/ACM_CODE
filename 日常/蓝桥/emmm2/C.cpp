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
int p[maxn];
int n,k;
bool check(int mid)
{
	int ma=0,mi=INF;
	int cnt=1;
	for(int i=1;i<=n;i++)
	{
		mi=min(mi,p[i]);
		ma=max(ma,p[i]);
		if(ma-mi>mid)
		{
			cnt++;
			mi=p[i];
			ma=p[i];
		}
	}
	return cnt<=k;
}
void solve()
{
	cin>>n>>k;
	int mi=INF,ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		mi=min(mi,p[i]);
		ma=max(ma,p[i]);
	}
	int l=0,r=ma-mi+10,ans=r;
	while(l<r-1)
	{
		ll mid=(l+r)>>1;
		if(check(mid))ans=mid,l=mid;
		else r=mid;
	}
	while(check(ans-1))ans--;
	
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