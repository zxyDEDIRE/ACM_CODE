#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=1e6;
struct node{
	int l,r,val,lazy;
}t[maxn<<2];
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r){
		cin>>t[rt].val;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=k*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
signed main()
{
	int n,m;
	cin>>n>>m;
	build(1,1,n);
	while(m--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int x,y,k;
			cin>>x>>y>>k;
			update(1,x,y,k);
		}
		else if(op==2)
		{
			int x,y;
			cin>>x>>y;
			cout<<query(1,x,y)<<endl;
		}
	}
}