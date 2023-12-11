#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int fa[N],son[N],sz[N],deep[N],top[N]; //fa表示节点的父亲，son表示节点的重儿子，sz表示节点的大小，deep表示节点的深度，top用来记录当前这个点所在重链的链首
int dfn=0,oldid[N],newid[N];   //newid表示当前节点对应的dfs序，oldid表示dfs序对应的原来的树的节点
vector<int>G[N];
#define ls (k<<1)
#define rs (k<<1|1)
#define mid (t[k].r+t[k].l>>1)
#define check (l<=t[k].l&&t[k].r<=r)
int a[N];
struct node
{
	int l,r;
	int Max;
	int lazyp;
}t[N<<2];
void pushup(int k)
{
	t[k].Max=max(t[ls].Max,t[rs].Max);
}
void f(int k,int v)
{
	t[k].Max+=v;
	t[k].lazyp+=v;
}
void pushdown(int k)
{
	f(ls,t[k].lazyp);
	f(rs,t[k].lazyp);
	t[k].lazyp=0;
}
void build(int k,int l,int r)
{
	t[k].l=l;
	t[k].r=r;
	if(l==r)
	{
		t[k].Max=a[oldid[l]];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(k);
}
void modify(int k,int l,int r,int v)
{
	if(l<=t[k].l&&t[k].r<=r)
	{
		t[k].Max+=v;
		t[k].lazyp+=v;
		return ;
	}
	pushdown(k);
	if(l<=mid)modify(k<<1,l,r,v);
	if(r>mid)modify(k<<1|1,l,r,v);
	pushup(k);
}
int query(int k,int l,int r)
{
	if(l<=t[k].l&&t[k].r<=r)
	{
		return t[k].Max;
	}
	pushdown(k);
	int ans=-0x3f3f3f;
	if(l<=mid)ans=max(ans,query(k<<1,l,r));
	if(r>mid)ans=max(ans,query(k<<1|1,l,r));
	return ans;
}
void dfs1(int x,int father)
{
	deep[x]=deep[father]+1;
	fa[x]=father;
	son[x]=0;
	sz[x]=1;
	for(auto i:G[x])
	{
		if(i==father)continue;
		dfs1(i,x);
		sz[x]+=sz[i];
		if(son[x]==0||sz[son[x]]<sz[i])son[x]=i;
	}
}
void dfs2(int x,int topx) //x表示当前节点，topx表示当前重链的顶点
{
	top[x]=topx; 
	newid[x]=++dfn;
	oldid[dfn]=x;
	if(son[x])dfs2(son[x],topx);
	for(auto i:G[x])
	{
		if(i==fa[x]||i==son[x])continue;
		dfs2(i,i);//开启一条新的重链
	}
}
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(deep[x]<deep[y])swap(x,y);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])swap(x,y);
	return x;

}
void modi(int x,int y,int v)
{
	while(top[x]!=top[y])
	{
		if(deep[x]<deep[y])swap(x,y);
		modify(1,newid[top[x]],newid[x],v);
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])swap(x,y);
	modify(1,newid[x],newid[y],v);
}
int que(int x,int y)
{
	int ans=-1;
	while(top[x]!=top[y])
	{
		if(deep[x]<deep[y])swap(x,y);
		ans=max(ans,query(1,newid[top[x]],newid[x]));
		x=fa[top[x]];
	}
	if(deep[x]>deep[y])swap(x,y);
	ans=max(ans,query(1,newid[x],newid[y]));
	return ans;
}
int main()
{
	solve();
}