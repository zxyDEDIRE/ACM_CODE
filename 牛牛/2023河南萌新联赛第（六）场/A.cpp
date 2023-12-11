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
int cnt[maxn][33];
ll p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		for(int j=0;j<=31;j++)
		{
			if(p[i]&(1ll<<j))
				cnt[i][j]++;
			cnt[i][j]+=cnt[i-1][j];
		}
	}
	int q;cin>>q;
	while(q--)
	{
		int l,r,tot;
		ll ans=0;
		cin>>l>>r;
		tot=r-l+1;
		for(int i=0;i<31;i++)
		{
			int x=cnt[r][i]-cnt[l-1][i];
			if(x*2<tot)ans|=(1ll<<i);
		}
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}