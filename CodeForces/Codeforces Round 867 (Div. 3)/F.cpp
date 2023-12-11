#include<bits/stdc++.h>
#define mid ((t[rt].l+t[rt].r)>>1)
using namespace std;
using ll=long long;
const int maxn=1e5+10;
int to[maxn<<1],nex[maxn<<1],head[maxn<<1],cnt;
ll dep[maxn];
int fa[maxn],siz[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn];
int tot;
ll n,m,r,p;
ll k,c;
int res;
struct Seg{
	int l,r;ll val,lazy;
}t[maxn<<2];
inline void add(int from,int too)
{
	to[++cnt]=too;
	nex[cnt]=head[from];
	head[from]=cnt;
}

inline void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
inline void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy;
		t[rt<<1|1].val+=t[rt].lazy;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
inline void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r)
	{
		t[rt].val=dep[di[l]];
		return ;
	}
	int md=(l+r)>>1;
	build(rt<<1,l,md);
	build(rt<<1|1,md+1,r);
	pushup(rt);
}
inline ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	if(t[rt].lazy) pushdown(rt);
	ll ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
inline void update(int rt,int l,int r,ll k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=k;
		t[rt].val+=k;
		return ;
	}
	if(t[rt].lazy)pushdown(rt);
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
inline void upSonSub(int x)
{
	update(1,id[x],id[x]+siz[x]-1,-k);
	if(id[x]>1)update(1,1,id[x]-1,k);
	if(id[x]+siz[x]-1<n)update(1,id[x]+siz[x],n,k);
}
inline void upSonAdd(int x)
{
	update(1,id[x],id[x]+siz[x]-1,k);
	if(id[x]>1)update(1,1,id[x]-1,-k);
	if(id[x]+siz[x]-1<n)update(1,id[x]+siz[x],n,-k);
}
inline ll qSon(int x)
{
	return query(1,id[x],id[x]+siz[x]-1);
}



inline void dfs1(int x,int f,ll deep)//当前点，父亲点，深度
{
	dep[x]=deep;	//记录每个点的深度
	fa[x]=f;	//记录每个点的父亲
	siz[x]=1;	//记录每个点子树大小
	son[x]=0;
	int maxson=-1;	//记录重儿子的儿子树 要计较
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==f)continue;
		dfs1(y,x,deep+k);	//遍历儿子
		siz[x]+=siz[y];	//加上子树大小
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//记录比较重儿子
	}
}
inline void dfs2(int x,int topf)//当前节点，topf当前链的链首
{
	id[x]=++tot;	//标记每个点的新编号
	di[tot]=x;	//每个点的初始值赋值到新编号
	top[x]=topf;	//当前点的链首
	if(!son[x])return ;	//没有儿子
	dfs2(son[x],topf);	//先处理重儿子，在处理轻儿子
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==fa[x]||y==son[x])
			continue;
		dfs2(y,y);//新建重链
	}
}
ll ans=0;
void dfs(int x,ll num)
{
	// cout<<t[1].val<<" "<<num<<" "<<x<<endl;
	// if(t[1].val-num<ans)return ;
	ans=max(ans,t[1].val-num);
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==fa[x])continue;
		upSonSub(y);
		dfs(y,num+c);
		upSonAdd(y);
	}
}
void solve()
{
	cin>>n>>k>>c;
	for(int i=1;i<=n;i++){
		head[i]=nex[i]=to[i]=0;
	}
	ans=0;
	cnt=0;
	tot=0;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs1(1,0,0);
	dfs2(1,1);
	build(1,1,n);
	dfs(1,0);
	cout<<ans<<"\n";
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}