#include<bits/stdc++.h>
#define int long long
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	ll l,r,val,lazy;
}t[maxn<<2];
int n,q,ans;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=t[rt].lazy=0;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy>0)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
	else if(t[rt].lazy==-1)
	{
		t[rt<<1].val=0;
		t[rt<<1|1].val=0;
		t[rt<<1].lazy=-1;
		t[rt<<1|1].lazy=-1;
		t[rt].lazy=0;
	}
}
void add(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{ 
		t[rt].val+=k*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)add(rt<<1,l,r,k);
	if(r>mid)add(rt<<1|1,l,r,k);
	pushup(rt);
}
void query(int rt,int x)
{
	if(t[rt].l==t[rt].r)
	{
		ans=t[rt].l;
		t[rt].val-=x;
		return ;
	}
	pushdown(rt);
	ll a=t[rt<<1].val;
	ll b=t[rt<<1|1].val;
	if(a<x)
	{
		t[rt<<1].val=0;
		t[rt<<1].lazy=-1; 
		query(rt<<1|1,x-a);
	}
	else
	{
		query(rt<<1,x);
	}
	pushup(rt);
}
int f(int rt,int l)
{
	if(t[rt].l==t[rt].r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return f(rt<<1,l);
	else return f(rt<<1|1,l);
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		int fl,x,y,k;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
		else
		{
			cin>>x;
			if(x>t[1].val)cout<<"Trote_w is sb\n";
			else
			{
				query(1,x);
				cout<<ans<<endl;
			}
		}
	}
}
signed main()
{	ios
	int __;cin>>__;
	while(__--)
		solve();
}