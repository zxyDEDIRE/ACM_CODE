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

struct Seg{
	int l,r,val;
}t[maxn<<2];
int c[maxn],di[maxn];
// void f(int rt){};
void pushup(int rt){
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
};
void pushdown(int rt){};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=c[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}


vector<pii>v[maxn];
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],id[maxn],tot;
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(auto [y,w]:v[x])
	{
		if(y==fa)continue;
		c[y]=w;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int topf){
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
int LCA(int x,int y)
{
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int qRange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,query(1,id[top[x]],id[x]));
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y){
		ans=max(ans,query(1,id[son[x]],id[y]));
	}

	return ans;
}

struct node{
	int x,y,w,op;
};
vector<node>p;
int n,m;
void solve()
{
	cin>>n>>m;
	dsu.init(n);
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		p.push_back({x,y,w,0});
	}
	sort(p.begin(),p.end(),[&](node a,node b){
		return a.w<b.w;
	});
	for(auto &[x,y,w,op]:p)
	{
		if(!dsu.same(x,y))
		{
			// cout<<"merge "<<x<<" "<<y<<" "<<w<<endl;
			v[x].push_back({y,w});
			v[y].push_back({x,w});
			dsu.merge(x,y);
			op=1;
		}
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	int cnt=0;
	for(auto [x,y,w,op]:p)
	{
		if(op==1)continue;
		int qs=qRange(x,y);
		if(qs==w)cnt++;
	}
	cout<<cnt<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}