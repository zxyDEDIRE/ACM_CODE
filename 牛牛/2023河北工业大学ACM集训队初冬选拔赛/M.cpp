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
pii p[maxn];
int n,q;
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+n,greater<pii>());
	// for(int i=1;i<n;i++)
	// 	cout<<p[i].first<<" "<<p[i].second<<endl;
	cin>>q;
	while(q--)
	{
		int x,y,w;
		cin>>x>>y>>w;
		int fl=lower_bound(p+1,p+n,pii{x,y},greater<pii>())-p;
		if(fl<=w)cout<<"YES\n";
		else cout<<"NO\n";
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