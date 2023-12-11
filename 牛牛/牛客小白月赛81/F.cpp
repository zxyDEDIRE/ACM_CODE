#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
vector<pii>p[maxn];
int a[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	p[1].push_back({1,a[1]});
	for(int i=2;i<=n;i++)
	{
		p[i].push_back({i,a[i]});
		for(auto [x,y]:p[i-1])
		{
			if(__gcd(a[i],y)!=p[i].back().second)
			p[i].push_back({x,__gcd(a[i],y)});
			if(p[i].back().second==1)break;
		}
	}
	while(m--)
	{
		int l,r;
		cin>>l>>r;
		int fl=lower_bound(p[r].begin(),p[r].end(),pii(l,0),greater<pii>())-p[r].begin();
		cout<<fl<<endl;
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