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

struct Seg{
	int l,r,val;
}t[maxn<<2];
// void f(int rt){};
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void pushdown(int rt){};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
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

int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	vector<pii>Q;
	while(m--)
	{
		char ch;int x,y,ans;
		cin>>ch;
		if(ch=='Q')
		{
			cin>>x>>y;
			ans=qRange(x,y);
			if(ans)cout<<"No\n";
			else cout<<"Yes\n";
		}
		else if(ch=='C')
		{
			cin>>x>>y;
			if(dep[x]<dep[y])swap(x,y);
			update(1,id[x],id[x],1);
			Q.push_back({x,y});
		}
		else if(ch=='U')
		{
			cin>>x;
			auto [l,r]=Q[x-1];
			if(dep[l]<dep[r])swap(l,r);
			update(1,id[l],id[l],-1);
		}
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