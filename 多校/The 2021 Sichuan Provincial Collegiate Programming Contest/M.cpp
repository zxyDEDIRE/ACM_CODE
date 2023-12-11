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
ll t[maxn];
ll s[maxn];
ll n,k,x;
void solve()
{
	cin>>n>>k>>x>>p[0];
	for(int i=1;i<=n;i++)
		cin>>s[i];
	sort(s+1,s+1+n,[&](int a,int b){return a>b;});
	t[0]=0;
	for(int i=1;i<=k;i++)
		cin>>t[i];
	for(int i=1;i<=k;i++)
		cin>>p[i];
	int l=1;
	for(int i=0;i<=k;i++)
	{
		ll _t=p[i]-t[i];
		while(l<=n && s[l]*_t>=x)
			l++;
	}
	cout<<l-1<<endl;

}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}