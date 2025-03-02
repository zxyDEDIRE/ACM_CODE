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
map<int,int>mp;
vector<pii>v[maxn];
int n,m,s,t;
void solve()
{
	cin>>n>>m;
	mp.clear();
	int tot=n;
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		if(!mp.count(c))mp[c]=++tot;
		c=mp[c];
		v[x].push_back({c,1});
		v[c].push_back({x,1});
	}

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