/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct Seg{int l,r,val;};
vector<int>siz,dep,son,f,id,di,top,c;
vector<vector<pii>>v;
vector<bool>vis;
vector<Seg>t;
set<int>s;
int tot;
int n,m;
void init()
{
	vis.resize(n+1,0);
	v.resize(n+1);
	siz.resize(n+1);
	f.resize(n+1);
	dep.resize(n+1);
	son.resize(n+1);
	id.resize(n+1);
	di.resize(n+1);
	top.resize(n+1);
	t.resize(n*4+1);
	c.resize(n+1);
	s.clear();
	tot=0;
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0ll};
	if(l==r){
		t[rt].val=1ll*c[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l>r)return 0;
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void dfs1(int x,int fa)
{
	siz[x]=1;
	f[x]=fa;
	dep[x]=dep[fa]+1;
	for(auto [y,w]:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		c[y]=w;
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto [y,w]:v[x])
	{
		if(y==son[x]||y==f[x])continue;
		dfs2(y,y);
	}
}
int qRange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans+=query(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans+=query(1,id[x],id[y]);
	ans-=c[x];
	return ans;
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		int x;
		cin>>x;
		std::set<int>::iterator it;
		if(!vis[id[x]])s.insert(id[x]);
		int a=di[(it=s.lower_bound(id[x]))==s.begin()?*s.rbegin():*(--it)];
		int b=di[(it=s.upper_bound(id[x]))==s.end()?*s.begin():*(it)];
		if(vis[id[x]])s.erase(id[x]);
		// cout<<"a:"<<a<<" x:"<<x<<" b:"<<b<<" "<<s.size()<<endl;
		// for(auto i:s)
			// cout<<i<<" "<<di[i]<<endl;
		ll now=qRange(a,x)+qRange(b,x)-qRange(a,b);

		if(!vis[id[x]])vis[id[x]]=1,ans+=now;
		else vis[id[x]]=0,ans-=now;
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
4 2
1 2 30
2 3 50
2 4 60
2
3
*/