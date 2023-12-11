#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=5e6+100;
int a[maxn],b[maxn];
vector<pii>v[maxn];
bitset<maxn>vis;
ll ans=0;
ll cnt=0;
int n;
void dfs(int x)
{
	vis[x]=1;
	for(auto [y,w]:v[x]){
		if(w)a[x]++;
		else b[x]++;

		if(vis[y])
		{
			
		}
		else
		{
			dfs(y);
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int k,y,w;
		cin>>k;
		while(k--){
			cin>>y>>w;
			v[i].push_back({y,w});
		}
	}
	dfs(1);
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}