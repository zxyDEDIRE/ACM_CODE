#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
const int maxn=1e6;
int p[maxn];
int n,T;
struct Seg{
	ll l,r,val,lazy;
}t[maxn<<1][2];
void build(int fl,int rt,int l,int r)
{
	t[rt][fl].l=l;
	t[rt][fl].r=r;
	if(l==r)
	{
		return ;
	}
	int m=(t[rt][fl].l+t[rt][fl].r)>>1;
	build(fl,rt<<1,l,m);
	build(fl,rt<<1|1,m+1,r);
	
}
void update(int fl,int rt,int l,int r,int k)
{
	if(l<=t[rt][fl].l&&t[rt][fl].r<=r)
	{
		t[rt][fl].lazy+=k;
		t[rt][fl].val+=(t[rt][fl].r-t[rt][fl].l+1)*k;
		return ;
	}
	int m=(t[rt][fl].l+t[rt][fl].r)>>1;
	if(l<=m)	update(fl,rt<<1,l,r,k);
	if(r>m)	update(fl,rt<<1|1,l,r,k);
	t[rt][fl].val=t[rt<<1][fl].val+t[rt<<1|1][fl].val;
}
int query(int fl,int rt,int l,int r)
{
	if(l<=t[rt][fl].l&&t[rt][fl].r<=r)
	{
		return t[rt][fl].val;
	}
	int m=(t[rt][fl].l+t[rt][fl].r)>>1;
	int ans1=0,ans2=0;
	if(l<=m)ans1=query(fl,rt<<1,l,r);
	if(r>m)ans2=query(fl,rt<<1|1,l,r);
	return ans1+ans2;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>T;
	for(int i=1;i<=n;i++)
		cin>>p[i];

	build(0,1,1,n);
	build(1,1,1,n);

	while(T--)
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
	}
}