#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
const int mod=1e9+7;
vector<int >G[N];
int d[N],sz[N],fa[N],son[N],top[N],L[N],id[N],tot=0;
void dfs1(int x,int father)
{
	son[x]=0;fa[x]=father;sz[x]=1;d[x]=d[father]+1;
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(v==father)continue;
		dfs1(v,x);
		sz[x]+=sz[v];
		if(!son[x]||sz[son[x]]<sz[v])son[x]=v;	
	} 
}
void dfs2(int x,int topx)
{
	top[x]=topx;
	L[x]=++tot;
	id[tot]=x;
	if(son[x])dfs2(son[x],topx);
	for(int i=0;i<G[x].size();i++)
	{
		int v=G[x][i];
		if(v==fa[x]||v==son[x])continue;
		dfs2(v,v);
	}
}
typedef long long ll;
struct node
{
	int l,r;
	ll sum,sum1;
	ll lazyp;
}t[N<<2];
node operator +(const node &A,const node &B)
{
	node c;
	c.l=A.l;c.r=B.r;c.lazyp=0;
	c.sum=(A.sum+B.sum)%mod;
	c.sum1=(A.sum1+B.sum1+A.sum*B.sum)%mod;
}
void f(int k,ll v)
{
	ll len=(t[k].r-t[k].l+1);
	t[k].sum1=(t[k].sum1%mod+(len-1)*t[k].sum%mod*v%mod+len*(len-1)/2%mod*v%mod*v%mod)%mod;
	t[k].sum+=len*v;
	t[k].sum%=mod;
	t[k].lazyp+=v;
	t[k].lazyp%=mod;
}
void pushdown(int k)
{
	f(k<<1,t[k].lazyp);
	f(k<<1|1,t[k].lazyp);
	t[k].lazyp=0;
}
#define mid (t[k].l+t[k].r>>1)
int a[N];
void build(int k,int l,int r)
{
	t[k].l=l;t[k].r=r;t[k].lazyp=0;
	if(l==r)
	{
		t[k].sum1=0;
		t[k].sum=a[id[l]];
		return ;
	}
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k]=t[k<<1]+t[k<<1|1];
}
void modify(int k,int l,int r,int v)
{
	if(l<=t[k].l&&t[k].r<=r)
	{
		f(k,v);
		return ;
	}
	pushdown(k);
	if(l<=mid)modify(k<<1,l,r,v);
	if(r>mid)modify(k<<1|1,l,r,v);
	t[k]=t[k<<1]+t[k<<1|1];
}
node query(int k,int l,int r)
{
	if(l<=t[k].l&&t[k].r<=r)
	{
		return t[k];
	}
	long long ans=0;
	pushdown(k);
	if(r<=mid)return query(k<<1,l,r);
	else if(l>mid)return query(k<<1|1,l,r);
	else return query(k<<1,l,r)+query(k<<1|1,l,r);
}
void change(int l,int r,int v)
{
	while(top[l]!=top[r])
	{
		if(d[top[l]]<d[top[r]])swap(l,r);
		modify(1,L[top[l]],L[l],v);
		l=fa[top[l]];
	}
	if(d[l]>d[r])swap(l,r);
	modify(1,L[l],L[r],v);
}
long long query1(int l,int r)
{
	long long ans=0;
	while(top[l]!=top[r])
	{
		if(d[top[l]]<d[top[r]])swap(l,r);
		ans+=query(1,L[top[l]],L[l]).sum1;
		ans%=mod;
		l=fa[top[l]];
	}
	if(d[l]>d[r])swap(l,r);
	ans+=query(1,L[l],L[r]).sum1;
	return ans%mod;
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int l,r;
	for(int i=1;i<n;i++)
	{
		cin>>l>>r;
		G[l].push_back(r);
		G[r].push_back(l);
	}
	dfs1(1,1);
	dfs2(1,1);
	build(1,1,n);
	int op,va;
	while(m--)
	{
		cin>>op;
		if(op==1)
		{
			cin>>l>>va;
			modify(1,L[l],L[l]+sz[l]-1,va);
		}
		else if(op==2)
		{
			cin>>l>>r>>va;
			change(l,r,va);
		}	
		else 
		{
			cin>>l>>r;
			printf("%lld\n",query1(l,r)%mod);
		}
	} 
}
