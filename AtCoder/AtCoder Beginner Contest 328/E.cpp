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
	int x,y;ll w;
}p[maxn];
int li[maxn];
ll P;
int n,m;
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;
ll ans=1e18;
void dfs(int x,int y)
{
	if(y==n-1)
	{
		dsu.init(n);
		int flag=1;
		ll now=0;
		for(int i=1;i<=n-1;i++)
		{
			auto [x,y,w]=p[li[i]];
			if(dsu.same(x,y)){flag=0;break;}
			dsu.merge(x,y);
			now=(now+w)%P;
		}
		if(flag)ans=min(ans,now);
		return ;
	}
	if(x>m)return ;
	dfs(x+1,y);
	li[y+1]=x;
	dfs(x+1,y+1);
}
void solve()
{
	cin>>n>>m>>P;
	for(int i=1;i<=m;i++){
		auto &[x,y,w]=p[i];
		cin>>x>>y>>w;w%=P;
	}
	dfs(1,0);
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}