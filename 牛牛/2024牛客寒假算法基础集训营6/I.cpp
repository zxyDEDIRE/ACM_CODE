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
ll a[maxn];
ll b[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	ll mi_a = INF, ma_a = -INF;
	ll mi_pre = INF, ma_pre = -INF;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mi_pre = min(a[i], mi_pre + a[i]);
		ma_pre = max(a[i], ma_pre + a[i]);
		mi_a = min(mi_a, mi_pre);
		ma_a = max(ma_a, ma_pre);
	}
	ll mi_b = INF, ma_b = -INF;
	mi_pre = INF, ma_pre = -INF;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		mi_pre = min(b[i], mi_pre + b[i]);
		ma_pre = max(b[i], ma_pre + b[i]);
		mi_b = min(mi_b, mi_pre);
		ma_b = max(ma_b, ma_pre);
	}
	cout<<max({ma_a*ma_b, ma_a*mi_b, mi_a*ma_b, mi_a*mi_b})<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}