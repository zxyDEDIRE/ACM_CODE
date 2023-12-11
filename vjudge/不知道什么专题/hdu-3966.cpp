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
const int maxn=50000+100;
struct Seg{
	int l,r,val,lazy;
}t[maxn*3];
vector<int>v[maxn];
int siz[maxn],f[maxn],son[maxn],dep[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int p[maxn];
int n,m,q;
void init()
{
	for(int i=1;i<=n;i++){
		v[i].clear();
	}
	tot=0;
}
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(auto y:v[x])
		if(y!=fa)
		{
			dfs1(y,x);
			siz[x]+=siz[y];
			if(siz[y]>siz[son[x]])
				son[x]=y;
		}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
		if(y!=f[x]&&y!=son[x])
			dfs2(y,y);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r){
		t[rt].val=p[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int w)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val+=w*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=w;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,w);
	if(r>mid)update(rt<<1|1,l,r,w);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void upRange(int x,int y,int w)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],w);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],w);
}
void solve()
{
	while(cin>>n>>m>>q)
	{
		init();
		for(int i=1;i<=n;i++)
			cin>>p[i];
		for(int i=1;i<n;i++)
		{
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		dfs1(1,0);
		dfs2(1,1);
		build(1,1,n);
		while(q--)
		{
			char op;int x,y,w;
			cin>>op;
			if(op=='I')
			{
				cin>>x>>y>>w;
				upRange(x,y,w);
			}
			else if(op=='D')
			{
				cin>>x>>y>>w;
				upRange(x,y,-w);
			}
			else
			{
				cin>>x;
				cout<<query(1,id[x],id[x])<<endl;
			}
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}