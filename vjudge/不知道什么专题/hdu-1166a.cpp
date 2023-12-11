#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int maxn=1e6;
int p[maxn];
int n,T;
struct Seg{
	ll l,r,val,lazy;
}t[maxn<<1];
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].lazy=0;
	if(l==r)
	{
		t[rt].val=p[l];
		return ;
	}
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
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	string ch;
	int l,r,c;
	while(cin>>ch)
	{
		if(ch=="End")break;
		if(ch=="Add")
		{
			cin>>l>>c;
			update(1,l,l,c);
		}
		else if(ch=="Sub")
		{
			cin>>l>>c;
			update(1,l,l,-c);
		}
		else if(ch=="Query")
		{
			cin>>l>>r;
			cout<<query(1,l,r)<<endl;
		}
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __,_;cin>>__;
	for(_=1;_<=__;_++){
		cout<<"Case "<<_<<":\n";
		solve();
	}
	return 0;
}