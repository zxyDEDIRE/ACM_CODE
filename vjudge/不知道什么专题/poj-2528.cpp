/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<algorithm>
#include<iostream>
using namespace std;
#define endl "\n"
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Seg{
	int l,r,val,same;
}t[maxn<<3];
bool vis[maxn];
int l[maxn],r[maxn],w[maxn];
int n,m;
void pushup(int rt)
{
	if(t[rt<<1].same&&t[rt<<1|1].same&&t[rt<<1].val==t[rt<<1|1].val)
	{
		t[rt].val=t[rt<<1].val;
		t[rt].same=1;
	}
	else t[rt].same=0;
}
void pushdown(int rt)
{
	if(t[rt].same==1)
	{
		t[rt<<1].val=t[rt<<1|1].val=t[rt].val;
		t[rt<<1].same=t[rt<<1|1].same=1;
	}
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].same=1;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=k;
		t[rt].same=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
void query(int rt,int l,int r)
{
	if(t[rt].same==1)
	{
		vis[t[rt].val]=1;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)query(rt<<1,l,r);
	if(r>mid)query(rt<<1|1,l,r);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		vis[i]=0;
		cin>>l[i]>>r[i];
		w[2*i-1]=l[i],w[2*i]=r[i];
	}
	sort(w+1,w+1+n*2);
	m=unique(w+1,w+1+n*2)-w-1;
	build(1,1,m);
	for(int i=1;i<=n;i++)
	{
		int fa=lower_bound(w+1,w+1+m,l[i])-w;
		int fb=lower_bound(w+1,w+1+m,r[i])-w;
		if(fa>fb)swap(fa,fb);
		update(1,fa,fb,i);
	}
	query(1,1,m);
	int ans=0;
	for(int i=1;i<=n;i++)
		if(vis[i])
			ans++;
	cout<<ans<<endl;
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}