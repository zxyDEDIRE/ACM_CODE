#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int sum[maxn],p[maxn];
struct Seg{
	int l,r,val,lazy;
}t[maxn<<1];
int n,q;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=p[l];
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int k=t[rt].lazy;

		int lena=t[rt<<1].r-t[rt<<1].l+1;
		t[rt<<1].val=k*lena+sum[lena];
		t[rt<<1].lazy=k;

		k+=lena;
		int lenb=t[rt<<1|1].r-t[rt<<1|1].l+1;
		t[rt<<1|1].val=k*lenb+sum[lenb];
		t[rt<<1|1].lazy=k;

		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	//cout<<t[rt].l<<" "<<t[rt].r<<" "<<k<<endl;
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		
		int len=t[rt].r-t[rt].l+1;
		t[rt].val=len*k+sum[len];
		t[rt].lazy=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid&&r<=mid)update(rt<<1,l,r,k);
	else if(l>mid&&r>mid)update(rt<<1|1,l,r,k);
	else if(l<=mid&&r>mid)
	{
		update(rt<<1,l,r,k);
		int len=mid-max(l,t[rt<<1].l)+1;
		update(rt<<1|1,l,r,k+len);
	}
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
signed main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(0);cout.tie(0);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		sum[i]=sum[i-1]+i-1;
		cin>>p[i];
	}
	build(1,1,n);

	while(q--)
	{
		int fl,x,y,k;
		cin>>fl;
		if(fl==1)
		{
			cin>>x>>y>>k;
			update(1,x,y,k);
		}
		else if(fl==2)
		{
			cin>>x>>y;
			cout<<query(1,x,y)<<"\n";
		}
		for(int i=1;i<=n;i++)
			cout<<query(1,i,i)<<" ";
		cout<<endl;
	}
}
/*
0 1 2 3 4 5 6 7 8 9 10
*/