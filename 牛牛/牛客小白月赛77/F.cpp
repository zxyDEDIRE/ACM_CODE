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
map<ll,int>mp;
ll a,b;
void dfs(ll now,int step)
{
	if(now<a)return ;
	if(mp.count(now)&&mp[now]<step)return ;
	mp[now]=step;
	ll tmp=sqrt(now);
	if(tmp*tmp==now)dfs(tmp,step+1);
	if(now%2==0)dfs(now/2,step+1);
	dfs(now-1,step+1);
}
void solve()
{
	cin>>a>>b;
	dfs(b,0);
	cout<<mp[a]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}