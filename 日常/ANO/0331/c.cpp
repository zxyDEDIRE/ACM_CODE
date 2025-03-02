#include<bits/stdc++.h>
using namespace std;
using int64 = long long;
const int maxn=1e6;
int64 n,T,p[maxn];
struct SegTreeNode{
	int64 val;
	int64 lazy;
}segtree[maxn<<1];
void pushup(int rt)
{
	segtree[rt].val=segtree[rt<<1].val+segtree[rt<<1|1].val;
}
void pushdown(int rt,int64 ln,int64 rn)
{
	if(segtree[rt].lazy)
	{
		segtree[rt<<1].lazy+=segtree[rt].lazy;
		segtree[rt<<1|1].lazy+=segtree[rt].lazy;
		segtree[rt<<1].val+=segtree[rt].lazy*ln;
		segtree[rt<<1|1].val+=segtree[rt].lazy*rn;

		segtree[rt].lazy=0;
	}
}
void build(int l,int r,int rt)//建树
{
	segtree[rt].lazy=0;
	if(l==r)
	{
		segtree[rt].val=p[l];
		return ;
	}
	int m=(l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	pushup(rt);
}
void update(int L,int R,int64 c,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		segtree[rt].lazy+=c;
		segtree[rt].val+=c*(r-l+1);
		return ;
	}
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	if(L<=m)update(L,R,c,l,m,rt<<1);
	if(m<R)update(L,R,c,m+1,r,rt<<1|1);
	pushup(rt);
}
int64 query(int L,int R,int l,int r,int rt)
{
	if(L<=l&&r<=R)
	{
		return segtree[rt].val;
	}
	if(L>r||l>R)
		return 0;
	int m=(l+r)>>1;
	pushdown(rt,m-l+1,r-m);
	return query(L,R,l,m,rt<<1)+query(L,R,m+1,r,rt<<1|1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>T;
	for(int i=1;i<=n;i++)cin>>p[i];//存储数组

	build(1,n,1);//建树

	for(int i=1;i<=T;i++)
	{
		int64 fl,x,y,k;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>k;
			update(x,y,k,1,n,1);
		}
		else if(fl==2)
		{
			cin>>k;
			update(1,1,k,1,n,1);
		}
		else if(fl==3)
		{
			cin>>k;
			update(1,1,-k,1,n,1);
		}
		else if(fl==4)
		{
			cin>>x>>y;
			cout<<query(x,y,1,n,1)<<"\n";
		}
		else if(fl==5)
		{
			cout<<query(1,1,1,n,1)<<"\n";
		}
	}
}