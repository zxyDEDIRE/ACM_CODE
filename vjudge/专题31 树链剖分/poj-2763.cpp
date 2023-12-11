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
const int maxn=2e5+100;
struct Seg{
	int l,r,val;
}t[maxn<<2];
int c[maxn],id[maxn],di[maxn];
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void build(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
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
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}

struct Edge{
	int to,next,w,id;
}edge[maxn];
int head[maxn],cnt;
void add(int from,int to,int w,int id){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].id=id;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],tot;
int _id[maxn];
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
		int ID=edge[i].id;
		c[y]=w;
		_id[ID]=y;
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
int qRange(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans+=query(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		ans+=query(1,id[son[x]],id[y]);
	return ans;
}

int n,m,s;
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w,i);
		add(y,x,w,i);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	while(m--)
	{
		int op,x,y;
		cin>>op;
		if(op==0)
		{
			cin>>x;
			cout<<qRange(s,x)<<endl;
			s=x;
		}
		else
		{
			cin>>x>>y;
			update(1,id[_id[x]],id[_id[x]],y);
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}