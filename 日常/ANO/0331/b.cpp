#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
ll p[maxn],mod;
int n,T;
struct Seg{
	int l,r,val,la,lb;
}t[maxn<<1];
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].la=t[rt].lb=0;
	if(l==r)
	{
		t[rt].val=p[l];
		return ;
	}
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
}

void dfs(int rt,int l,int r)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<< t[rt].val <<endl;
	if(t[rt].l==t[rt].r)return ;
	int m=(t[rt].l+t[rt].r)>>1;
	dfs(rt<<1,l,r);
	dfs(rt<<1|1,l,r);
}
void pushdown(int rt)
{
	if(t[rt].la)
	{
		t[rt<<1].lb*=t[rt].la;
		t[rt<<1|1].lb*=t[rt].la;
		t[rt<<1].la+=t[rt].la;
		t[rt<<1|1].la+=t[rt].la;

		t[rt<<1].val*=t[rt].la;
		t[rt<<1|1].val*=t[rt].la;

		t[rt].la=0;
	}

	if(t[rt].lb)
	{
		t[rt<<1].lb+=t[rt].lb;
		t[rt<<1|1].lb+=t[rt].lb;

		int m=(t[rt].l+t[rt].r)>>1;
		t[rt>>1].val+=(m-t[rt].l+1)*t[rt].lb;
		t[rt>>1|1].val+=(t[rt].r-m)*t[rt].lb;

		t[rt].lb=0;
	}
}
void mull(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lb*=k;
		t[rt].la+=k;
		t[rt].val*=k;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)mull(rt<<1,l,r,k);
	if(r>m)mull(rt<<1|1,l,r,k);
	pushup(rt);
}
void add(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lb+=k;
		t[rt].val+=(t[rt].r-t[rt].l+1)*k;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)add(rt<<1,l,r,k);
	if(r>m)add(rt<<1|1,l,r,k);
	pushup(rt);
}
ll query(int rt,int l,int r)
{
//	if(t[rt].l>r||t[rt].r<l)return 0;
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
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>T>>mod;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	build(1,1,n);
//	cout<<"*";
	for(int i=1;i<=T;i++)
	{
		dfs(1,1,n);
		cout<<endl;
		int fl,x,y,k;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>k;
		//	mull(1,x,y,k);
		}
		else if(fl==2)
		{
			cin>>x>>y>>k;
			add(1,x,y,k);
		}
		else if(fl==3)
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
		dfs(1,1,n);
		cout<<endl;
	}
}