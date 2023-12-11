#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int maxn=1e6;
int n,m,T;
struct Seg{
	ll l,r,val,lazy;
}t[maxn<<1];
struct node{
	int x,y;
}p[maxn];
int a[maxn];
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].lazy=t[rt].val=0;
	if(l==r)
		return ;
	int m=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int m=(t[rt].l+t[rt].r)>>1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;

		t[rt<<1].val+=(m-t[rt].l+1)*t[rt].lazy;
		t[rt<<1|1].val+=(t[rt].r-m)*t[rt].lazy;

		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=k;
		t[rt].val+=(t[rt].r-t[rt].l+1)*k;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)	update(rt<<1,l,r,k);
	if(r>m)	update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	int ans1=0,ans2=0;

	if(l<=m)ans1=query(rt<<1,l,r);
	if(r>m)ans2=query(rt<<1|1,l,r);

	return ans1+ans2;

}
void solve()
{
	cin>>n;
	vector<int>v;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		a[++cnt]=p[i].x;
		a[++cnt]=p[i].y;
	}
	sort(a+1,a+1+cnt);
	m=unique(a+1,a+1+cnt)-a-1;
	build(1,1,m);
	for(int i=1;i<=n;i++)
	{
		int x=lower_bound(a+1,a+1+m,p[i].x)-a;
		int y=lower_bound(a+1,a+1+m,p[i].y)-a;
		cout<<x<<" "<<y<<endl;
		update(1,x,y,1);
	}
	int ma=0;
	for(int i=1;i<=m;i++)
		ma=max(ma,query(1,i,i));
	cout<<n-ma<<endl;
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)solve();
}