#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
struct Seg{
	ll l,r,val,lazy;
}t[maxn];
ll n,m,x;
inline void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	ll mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
inline void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].val+t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
inline void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
inline void update(int rt,int l,int r,int c)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=c*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=c;
		return ;
	}
	pushdown(rt);
	ll mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,c);
	if(r>mid)update(rt<<1|1,l,r,c);
	pushup(rt);
}
inline int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	ll ans1=0,ans2=0;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans1=query(rt<<1,l,r);
	if(r>mid)ans2=query(rt<<1|1,l,r);
	return ans1+ans2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>m>>x;
	build(1,1,n);
	while(m--)
	{
		ll op,l,r,k;
		cin>>op>>l>>r;
		if(op==1)
		{
			cin>>k;
			update(1,l,r,(k+x-1)/x);
		}
		else if(op==2)
		{
			cout<<query(1,l,r)<<"\n";
		}
	}
}