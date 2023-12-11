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
vector<pp(3)>q[maxn];
vector<int>v[maxn];
set<int>s[maxn];
int ans[maxn];
int id[maxn];
int l[maxn];
int n,m;
void dfs(int x,int fa)
{
	int ma=x;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		if(s[l[y]].size()>s[l[ma]].size())
			ma=y;
	}
	l[x]=l[ma];
	s[l[x]].insert(id[x]);
	for(auto y:v[x])
	{
		if(y==fa||y==ma)continue;
		for(auto i:s[l[y]])
			s[l[x]].insert(i);
	}
	for(auto [_l,_r,id]:q[x])
	{
		auto fl=s[l[x]].lower_bound(_l);
		if(fl!=s[l[x]].end())
		{
			if(*fl>=_l&&*fl<=_r)ans[id]=1;
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		l[i]=i;
		s[i].clear();
		v[i].clear();
		q[i].clear();
	}
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		id[x]=i;
	}
	for(int i=1;i<=m;i++){
		int x,y,w;
		cin>>x>>y>>w;
		ans[i]=0;
		q[w].push_back({x,y,i});
	}
	dfs(1,0);
	for(int i=1;i<=m;i++)
		cout<<(ans[i]?"YES\n":"NO\n");
	// cout<<endl;
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
/*
5 
*/