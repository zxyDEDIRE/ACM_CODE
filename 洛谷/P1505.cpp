/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Sge{
	int l,r,val,ma,mi,lazy;
}t[maxn<<2];
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int siz[maxn],fa[maxn],son[maxn],dep[maxn];
int top[maxn],id[maxn],di[maxn],w[maxn],tot;
int val[maxn];
int n;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs1(int x,int f,int deep)
{
	siz[x]=1;
	dep[x]=deep;
	fa[x]=f;
	int maxson=-1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f)continue;
		dfs1(y,x,deep+1);
		w[y]=edge[i].w;
		siz[x]+=siz[y];
		if(siz[y]>maxson)
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=t[rt].mi=t[rt].ma=w[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void f(int rt)
{
	int a=t[rt].ma;
	int b=t[rt].mi;
	t[rt].val=-t[rt].val;
	t[rt].ma=-b;
	t[rt].mi=-a;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		f(rt<<1);
		f(rt<<1|1);
		t[rt<<1].lazy^=1;
		t[rt<<1|1].lazy^=1;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val=t[rt].ma=t[rt].mi=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
void modify(int rt,int l,int r)
{
	if(l<=t[rt].l&t[rt].r<=r)
	{
		f(rt);
		t[rt].lazy^=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)modify(rt<<1,l,r);
	if(r>mid)modify(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l,int r,int op)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(op==1)return t[rt].val;
		else if(op==2)return t[rt].ma;
		else return t[rt].mi;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans;
	if(op==1)
	{
		ans=0;
		if(l<=mid)ans+=query(rt<<1,l,r,op);
		if(r>mid)ans+=query(rt<<1|1,l,r,op);
	}
	else if(op==2)
	{
		op=-INF;
		if(l<=mid)ans=max(ans,query(rt<<1,l,r,op));
		if(r>mid)ans=max(ans,query(rt<<1|1,l,r,op));
	}
	else
	{
		op=INF;
		if(l<=mid)ans=min(ans,query(rt<<1,l,r,op));
		if(r>mid)ans=min(ans,query(rt<<1|1,l,r,op));
	}
	return ans;
}
int qRange(int x,int y,int op)
{
	int ans;
	if(op==1)ans=0;
	else if(op==2)ans=-INF;
	else ans=INF;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]>dep[top[y]])swap(x,y);
		if(op==1)
			ans=ans+query(1,id[top[x]],id[x],op);
		else if(op==2)
			ans=max(ans,query(1,id[top[x]],id[x],op));
		else if(op==3)
			ans=min(ans,query(1,id[top[x]],id[x],op));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(op==1)
		ans=ans+query(1,id[x],id[y],op);
	else if(op==2)
		ans=max(ans,query(1,id[x],id[y],op));
	else ans=min(ans,query(1,id[x],id[y],op));
	return ans;
}
void upRange(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		modify(1,id[top[x]],id[x]);
		x=fa[top[x]];	
	}
	if(dep[x]>dep[y])swap(x,y);
	modify(1,id[x],id[y]);
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		add(x,y,w);
		add(y,x,w);
	}
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);
	int q;
	cin>>q;
	while(q--)
	{
		string op;
		cin>>op;
		if(op=="C")
		{

		}
		else if(op=="N")
		{

		}
		else if(op=="SUM")
		{

		}
		else if(op=="MAX")
		{

		}
		else if(op=="MIN")
		{

		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}