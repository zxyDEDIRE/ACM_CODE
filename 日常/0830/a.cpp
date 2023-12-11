#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
const int maxn=1e5+7;
int n,q;
struct node
{
	int l,r;
	int maxx;
	ll sum;
}t[maxn];
void pushup(int k)
{
	t[k].maxx=max(t[k<<1].maxx,t[k<<1|1].maxx);
	t[k].sum=t[k<<1].sum+t[k<<1|1].sum;
	return;
}
void build(int k,int l,int r)
{
	t[k]={l,r,0,0};
	// cout<<"k="<<k<<" l="<<l<<" r="<<r<<endl;
	if(l==r)
	{
		cin>>t[k].sum;
		t[k].maxx=t[k].sum;
		return;
	}
	int mid=(t[k].l+t[k].r)/2;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	pushup(k);
	return;
}
void modify(int k,int l,int r,int x)
{
	if(t[k].maxx<x)
	{
		// printf("t[%d].maxx=\n",k,t[k].maxx);
		return;
	}
	if(t[k].l==t[k].r)
	{
		t[k].sum%=x;
		t[k].maxx%=x;
		return;
	}
	int mid=(t[k].l+t[k].r)/2;
	// cout<<"k="<<k<<" l="<<t[k].l<<" r="<<t[k].r<<" mid="<<mid<<endl;
	if(l<=mid)
		modify(k<<1,l,r,x);
	if(mid<r)
		modify(k<<1|1,l,r,x);
	pushup(k);
	return;
}
void modify(int k,int l,int x)
{
	if(l==t[k].l&&t[k].r==l)
	{
		t[k].sum=x;
		t[k].maxx=x;
		return;
	}
	int mid=(t[k].l+t[k].r)/2;
	if(l<=mid)
		modify(k<<1,l,x);
	else
		modify(k<<1|1,l,x);
	pushup(k);
	return;
}
ll query(int k,int l,int r)
{
	if(l<=t[k].l&&t[k].r<=r)
		return t[k].sum;
	ll res=0;
	int mid=(t[k].l+t[k].r)/2;
	if(l<=mid)
		res+=query(k<<1,l,r);
	if(mid<r)
		res+=query(k<<1|1,l,r);
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>q;
	build(1,1,n);
	// cout<<"build finish\n\n\n";
	for(int i=1;i<=n;i++)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int l,r;cin>>l>>r;
			cout<<query(1,l,r)<<"\n";
		}
		if(op==2)
		{
			int l,r,x;
			cin>>l>>r>>x;
			// cout<<"mod L="<<l<<" R="<<r<<"\n";
			modify(1,l,r,x);
		}
		if(op==3)
		{
			int l,x;
			cin>>l>>x;
			modify(1,l,x);
		}
		// cout<<"test #"<<i<<":"<<query(1,1,n)<<"\n";
	}
	return 0;
}
