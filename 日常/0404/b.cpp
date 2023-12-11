#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[maxn],a[maxn];
ll n,la,lb,ans;
struct Seg{
	ll l,r,val;
}t[maxn<<2];

void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)return ;
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void update(int rt,int x)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val++;
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;

	if(x<=m)update(rt<<1,x);
	else update(rt<<1|1,x);
	pushup(rt);
}
void query(int rt,int x)
{
	if(t[rt].l==t[rt].r)
	{
		ans+=la*lb;
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	if(x<=m)
	{
		lb+=t[rt<<1|1].val;
		query(rt<<1,x);
	}
	else
	{
		la+=t[rt<<1].val;
		query(rt<<1|1,x);
	}
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i],a[i]=p[i];

	sort(p+1,p+1+n);
	int N=unique(p+1,p+1+n)-p-1;

	build(1,1,N);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(p+1,p+1+N,a[i])-p;
		update(1,a[i]);
	}
	
	for(int i=2;i<n;i++)
	{
		la=lb=0;
		query(1,a[i]);
	}
	cout<<ans<<endl;
}