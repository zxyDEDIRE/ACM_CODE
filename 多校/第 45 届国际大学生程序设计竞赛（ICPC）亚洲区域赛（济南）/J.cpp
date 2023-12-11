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
const int N=111;
vector<int>v[N];
vector<int>p[2];
ll ans[N];
int n;
void dfs(int x,int fa,int op=0)
{
	p[op].push_back(x);
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x,op^1);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	for(auto x:p[1])
		ans[x]|=(1ll<<59);
	for(auto x:p[0])
		ans[x]=(1ll<<59)-1;

	int cnt=0;
	for(auto x:p[0])
	{
		ans[x]^=(1ll<<cnt);
		for(auto y:v[x])
			ans[y]^=(1ll<<cnt);
		cnt++;
	}

	for(int i=1;i<=n;i++)
	{
		bitset<60>a(ans[i]);
		cout<<a<<endl;
		// cout<<ans[i]<<" ";
	}
	cout<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}