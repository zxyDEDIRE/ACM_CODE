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
const int N=2e3+100;
vector<pii>v[N];
int dis[N][N];
bool vis[N];
pii p[N];
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].first,p[i].second=i;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++){
			int x;cin>>x;
			v[i].push_back({j,x});
		}
	}
	sort(p+1,p+1+n,[&](pii a,pii b){
		if(a.first!=b.first)
			return a.first>b.first;
		return a.second<b.second;
	});
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}