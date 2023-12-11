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
struct node{
	ll l,r,cnt;
}p[maxn];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].l>>p[i].r;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.r>b.r;
	});

	vector<node>v;
	v.push_back({p[1].l,p[1].r,1});
	for(int i=2;i<=n;i++)
	{
		if(p[i].r==v.back().r)
		{
			v.back().cnt++;
			v.back().l=max(v.back().l,p[i].l);
		}
		else
		{
			v.push_back({p[i].l,p[i].r,1});
		}
	}

	reverse(v.begin(),v.end());
	ll ans=0;
	ll ma=0;
	for(auto [l,r,cnt]:v)
	{
		ma=max(ma,l);
		ans+=ma*cnt;
	}
	cout<<ans<<endl;
}
/*
3
1   100
 2 10
 3 5


3 3 3
*/
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __=1;
	while(__--)
		solve();
	return 0;
}