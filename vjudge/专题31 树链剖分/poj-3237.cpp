#include<iostream>
#include<algorithm>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;

struct Seg{
	int l,r,mi,ma,lazy;
}t[maxn<<2];
int c[maxn],id[maxn],di[maxn];
void ff(int rt){
	swap(t[rt].ma,t[rt].mi);
	t[rt].ma*=-1;
	t[rt].mi*=-1;
	t[rt].lazy*=-1;
};
void pushup(int rt){
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
};
void pushdown(int rt){
	if(t[rt].lazy==-1)
	{
		ff(rt<<1);
		ff(rt<<1|1);
		t[rt].lazy=1;
	}
};
void build(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].lazy=1;
	if(l==r){
		t[rt].ma=t[rt].mi=c[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update1(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].ma=t[rt].mi=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update1(rt<<1,l,r,k);
	if(r>mid)update1(rt<<1|1,l,r,k);
	pushup(rt);
}
void update2(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		ff(rt);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update2(rt<<1,l,r);
	if(r>mid)update2(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].ma;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=-1e9;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}

struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int n;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],tot;
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		int w=edge[i].w;
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
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
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
void upRange(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update2(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		update2(1,id[son[x]],id[y]);
}
int qRange(int x,int y)
{
	int ans=-1e9;
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,query(1,id[top[x]],id[x]));
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		ans=max(ans,query(1,id[son[x]],id[y]));
	return ans;
}

void init()
{
	for(int i=1;i<=n;i++)
		head[i]=0;
	cnt=0;
	tot=0;
}
pair<int,int>p[maxn];
void solve()
{
	cin>>n;
	init();
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
		p[i].first=x;
		p[i].second=y;
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(1)
	{
		string op;int i,x,y,w;
		cin>>op;
		if(op=="DONE")break;
		else if(op=="QUERY")
		{
			cin>>x>>y;
			cout<<qRange(x,y)<<endl;
		}
		else if(op=="CHANGE")
		{
			cin>>i>>w;
			x=p[i].first;
			y=p[i].second;
			if(dep[x]<dep[y])swap(x,y);
			update1(1,id[x],id[x],w);
		}
		else if(op=="NEGATE")
		{
			cin>>x>>y;
			upRange(x,y);
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}