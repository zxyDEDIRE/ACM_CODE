#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6+10;
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];
int p[maxn];
int n,q;
void pushup(int rt )
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
	t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
	t[rt<<1].lazy+=t[rt].lazy;
	t[rt<<1|1].lazy+=t[rt].lazy;
	t[rt].lazy=0;
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
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,1000000);
	while(q--)
	{
		int fl;
		int x,y,k;
		cin>>fl;
		if(fl==2)
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
		else if(fl==1)
		{
			cin>>x>>y>>k;
			update(1,x,y,k);
		}
	}
}