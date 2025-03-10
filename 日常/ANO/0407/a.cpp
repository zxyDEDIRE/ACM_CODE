#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
char p[maxn];
int n,q;
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];


void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		if(p[l]=='1')t[rt].val=1;
		else t[rt].val=0;
		return ;
	}
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val=(t[rt<<1].r-t[rt<<1].l+1)-t[rt<<1].val;
		t[rt<<1].lazy^=t[rt].lazy;

		t[rt<<1|1].val=(t[rt<<1|1].r-t[rt<<1|1].l+1)-t[rt<<1|1].val;
		t[rt<<1|1].lazy^=t[rt].lazy;

		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=(t[rt].r-t[rt].l+1)-t[rt].val;
		t[rt].lazy^=1;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)update(rt<<1,l,r);
	if(r>m)update(rt<<1|1,l,r);
	pushup(rt);
}

int query(int rt,int l,int r)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	int ans1=0,ans2=0;
	if(l<=m)
	{
		ans1=query(rt<<1,l,r);
	}
	if(r>m)
	{
		ans2=query(rt<<1|1,l,r);
	}
	return ans1+ans2;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	build(1,1,n);

	while(q--)
	{
		int fl,x,y;
		cin>>fl>>x>>y;
		if(fl==0)
		{
			update(1,x,y);
		}
		else
		{
			cout<<query(1,x,y)<<"\n";
		}
	}
}
/*
10111 01001
11001 01001
*/