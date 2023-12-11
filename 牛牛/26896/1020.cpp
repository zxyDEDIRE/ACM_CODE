#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
const ll INF=1e13;
const int maxn=1e6+10;
struct Seg{
	int l,r,num;
	ll ma,mi;
}t[maxn<<2];
ll p[maxn];
int n,q;
void pushup(int rt)
{
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
	t[rt].num=t[rt<<1].num+t[rt<<1|1].num;
}
void bulid(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		cin>>t[rt].ma;
		t[rt].mi=t[rt].ma;
		t[rt].num=1;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	bulid(rt<<1,l,mid);
	bulid(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].mi=INF;
		t[rt].ma=-INF;
		t[rt].num=0;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	pushup(rt);
}
int f(int rt,int x)
{
	if(t[rt].l==t[rt].r)return t[rt].l;
	int a=t[rt<<1].num;
	int b=t[rt<<1|1].num;
	if(x<=a)return f(rt<<1,x);
	else return f(rt<<1|1,x-a);
}
pii query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return {t[rt].mi,t[rt].ma};
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pii x;
	x={INF,-INF};
	if(l<=mid)
	{
		pii y=query(rt<<1,l,r);
		x.first=min(x.first,y.first);
		x.second=max(x.second,y.second);
	}
	if(r>mid)
	{
		pii y=query(rt<<1|1,l,r);
		x.first=min(x.first,y.first);
		x.second=max(x.second,y.second);
	}
	return x;
}
signed main()
{	ios
	
	cin>>n>>q;
	bulid(1,1,n);

	while(q--)
	{
		int fl,x,y;
		cin>>fl;
		if(fl==1)
		{
			cin>>x;
			x=f(1,x);
			update(1,x);
		}
		else
		{
			cin>>x>>y;
			x=f(1,x);
			y=f(1,y);
			pii ans=query(1,x,y);
			cout<<ans.first<<" "<<ans.second<<"\n";
		}
	}
	
}