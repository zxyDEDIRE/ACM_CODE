#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{
	int l,r;
	ll add,mul,val,ans;
}t[maxn];
ll p[maxn];
int n,q;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	t[rt].ans=t[rt<<1].ans+t[rt<<1|1].ans;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=t[rt].ans=t[rt].add=0;
	t[rt].mul=1;
	if(l==r){
		t[rt].val=p[l];
		t[rt].ans=p[l]*p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	t[rt<<1].ans=t[rt].add*t[rt].add*(t[rt<<1].r-t[rt<<1].l+1)+2*t[rt].add*t[rt<<1].val+t[rt<<1].ans*t[rt].mul*t[rt].mul;
	t[rt<<1|1].ans=t[rt].add*t[rt].add*(t[rt<<1|1].r-t[rt<<1|1].l+1)+2*t[rt].add*(t[rt<<1|1].val)+t[rt<<1|1].ans*t[rt].mul*t[rt].mul;

	t[rt<<1].val=t[rt].mul*t[rt<<1].val+(t[rt<<1].r-t[rt<<1].l+1)*t[rt].add;
	t[rt<<1|1].val=t[rt].mul*t[rt<<1|1].val+(t[rt<<1|1].r-t[rt<<1|1].l+1)*t[rt].add;

	t[rt<<1].mul=t[rt<<1].mul*t[rt].mul;
	t[rt<<1|1].mul=t[rt<<1|1].mul*t[rt].mul;

	t[rt<<1].add=t[rt<<1].add*t[rt].mul+t[rt].add ;
	t[rt<<1|1].add=t[rt<<1|1].add*t[rt].mul+t[rt].add ;

	t[rt].mul=1;
	t[rt].add=0;
}
void add(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].add+=k;
		t[rt].ans+=k*k*(t[rt].r-t[rt].l+1)+2*k*(t[rt].val);
		t[rt].val+=k*(t[rt].r-t[rt].l+1);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add(rt<<1,l,r,k);
	if(r>mid)add(rt<<1|1,l,r,k);
	pushup(rt);
}
void mull(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].mul*=k;
		t[rt].add*=k;
		t[rt].ans*=k*k;
		t[rt].val*=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)mull(rt<<1,l,r,k);
	if(r>mid)mull(rt<<1|1,l,r,k);
	pushup(rt);
}
ll queryval(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=queryval(rt<<1,l,r);
	if(r>mid)ans+=queryval(rt<<1|1,l,r);
	return ans;
}
ll queryans(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].ans;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=queryans(rt<<1,l,r);
	if(r>mid)ans+=queryans(rt<<1|1,l,r);
	return ans;
}
int main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,10000);

	while(q--)
	{
		int fl,x,y,k;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y;
			cout<<queryval(1,x,y)<<endl;
		}
		else if(fl==2)
		{
			cin>>x>>y;
			cout<<queryans(1,x,y)<<endl;
		}
		else if(fl==3)
		{
			cin>>x>>y>>k;
			mull(1,x,y,k);
		}
		else if(fl==4)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
	}
}