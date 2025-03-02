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
vector<int>dep[maxn];
vector<int>v[maxn];
int n,s,t;
void dfs(int x,int d, int fa){
	dep[d].push_back(x);
	for(auto y:v[x]){
		if(y==fa)continue;
		dfs(y,d+1,x);
	}
}
void solve()
{
	cin>>n>>t>>s;
	for(int i=0;i<=n;i++){
		dep[i].clear();
		v[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(s, 0, -1);
	for(int i=n-1;i>=0;i--){
		for(auto x:dep[i])
			cout<<x<<" ";
	}
	cout<<endl;
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