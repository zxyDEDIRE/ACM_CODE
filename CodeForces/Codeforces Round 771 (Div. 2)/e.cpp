/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6+10;
struct Seg{
	int l,r,col,val;
	bool same;
}t[maxn<<2];
int val[maxn];
int n,q;
void pushup(int rt)
{
	if(t[rt<<1].same&&t[rt<<1|1].same&&t[rt<<1].col==t[rt<<1|1].col)
	{
		t[rt].same=1;
		t[rt].col=t[rt<<1].col;
	}
	else t[rt].same=0;
}
void pushdown(int rt)
{
	if(t[rt].same)
	{
		t[rt<<1].val+=t[rt].val;
		t[rt<<1|1].val+=t[rt].val;
		t[rt<<1].col=t[rt].col;
		t[rt<<1|1].col=t[rt].col;
		t[rt].val=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].col=t[rt].same=1;
	t[rt].val=0;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,int c)
{
	if((l<=t[rt].l)&&(t[rt].r<=r)&&t[rt].same)
	{
		t[rt].val+=val[t[rt].col];
		t[rt].col=c;
		t[rt].val-=val[t[rt].col];
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,c);
	if(r>mid)update(rt<<1|1,l,r,c);
	pushup(rt);
}
int query(int rt,int l)
{
	if(t[rt].l==t[rt].r)
		return t[rt].val+val[t[rt].col];
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		string fl;
		cin>>fl;
		if(fl=="Color")
		{
			int l,r,c;
			cin>>l>>r>>c;
			update(1,l,r,c);
		}
		else if(fl=="Add")
		{
			int c,x;
			cin>>c>>x;
			val[c]+=x;
		}
		else
		{
			int x;
			cin>>x;
			cout<<query(1,x)<<endl;
		}
		
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}