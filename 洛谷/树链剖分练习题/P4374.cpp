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
const int INF=2e9+7;
const int maxn=1e6+100;

struct Seg{
	int l,r,val;
}t[maxn<<2];
// void f(int rt){};
void pushup(int rt){};
void pushdown(int rt){
	t[rt<<1].val=min(t[rt<<1].val,t[rt].val);
	t[rt<<1|1].val=min(t[rt<<1|1].val,t[rt].val);
};
void build(int rt,int l,int r){
	t[rt]={l,r,INF};
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)return query(rt<<1,l,r);
	if(r>mid)return query(rt<<1|1,l,r);
	return ans;
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val=min(t[rt].val,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
}


vector<int>v[maxn];
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],id[maxn],di[maxn],tot;
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
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
	for(auto y:v[x])
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
void upRange(int x,int y,int w){
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],w);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		update(1,id[son[x]],id[y],w);
}

vector<pii>P;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		P.push_back({x,y});
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(m--)
	{
		int x,y,w;
		cin>>x>>y>>w;
		upRange(x,y,w);
	}
	for(auto [x,y]:P)
	{
		if(dep[x]<dep[y])swap(x,y);
		int ans=query(1,id[x],id[x]);
		if(ans==INF)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}