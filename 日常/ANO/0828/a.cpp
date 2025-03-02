#include <bits/stdc++.h>
//#define int long long

#define endl '\n'
using namespace std;
using ll=long long;
using pii=pair<int,int>;

const int maxn=100005;

int n,m;
int a[maxn];

struct node
{
	int l,r;
	int cnt;
}t[maxn<<2][21];

void build(int k,int i,int l,int r)
{
	t[k][i]={l,r};
	if(l==r)
	{
		t[k][i].cnt=(a[l]>>i)&1;
		return;
	}
	int mid=(t[k][i].l+t[k][i].r)/2;
	build(k<<1,i,l,mid);
	build(k<<1|1,i,mid+1,r);
	t[k][i].cnt=t[k<<1][i].cnt+t[k<<1|1][i].cnt;
	return;
}

int query(int k,int i,int l,int r)
{
	cout<<t[k][i].l<<" "<<t[k][i].r<<" "<<k<<endl;
	if(l<=t[k][i].l&&t[k][i].r<=r)
	{
		return t[k][i].cnt;
	}
	int mid=(t[k][i].l+t[k][i].r)>>1;

	int res=0;
	if(l<=mid){
		res+=query(k<<1,i,l,r);
	}
		
	if(r>mid){
		cout<<"r"<<endl;
		res+=query(k<<1|1,i,l,r);
	}
		
	return res;
}

void modify(int k,int i,int l,int r,int x)
{
	// cout<<k<<" "<<i<<" "<<l<<" "<<r<<" "<<x<<"\n";
	if(l<=t[k][i].l&&t[k][i].r<=r)
	{
		// cout<<"k="<<k<<endl;
		t[k][i].cnt=t[k][i].r-t[k][i].l+1-t[k][i].cnt;
		return;
	}
	int mid=(t[k][i].l+t[k][i].r)/2;
	if(l<=mid)
		modify(k<<1,i,l,r,x);
	// if(mid<r)
	// 	modify(k<<1|1,i,l,r,x);
	return;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=0;i<=20;i++)
		build(1,i,1,n);
	cin>>m;
	while(m--)
	{
		int op,l,r;
		cin>>op>>l>>r;
		// cout<<"op="<<op<<endl;
		if(op==1)
		{
			int res=0;
			for(int i=0;i<=20;i++){
				// cout<<query(1,i,l,r)<<"\n";
				res+=query(1,i,l,r)*(1<<i);
				// cout<<i<<endl;
			}
			cout<<res<<endl;
		}
		if(op==2)
		{
			int x;cin>>x;
			for(int i=0;i<=20;i++)
				modify(1,i,l,r,x);
			// cout<<"finish"<<endl;
		}
	}
	return 0;
}
/*
5
4 10 3 13 7
1
1 2 4
*/