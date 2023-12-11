#include<bits/stdc++.h>
#define int long long
#define ls rt<<1
#define rs rt<<1|1
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{
	int l,r,val;
}t[maxn];
int n,cnt,p;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r&&l==t[rt].l)
	{
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
signed main()
{
	cin>>n>>p;
	int t=0;
	build(1,1,200001);
	for(int i=1;i<=n;i++)
	{
		char fl;
		int x;
		cin>>fl>>x;
		if(fl=='A')
		{
			update(1,++cnt,(t+x)%p);
		}
		else if(fl=='Q')
		{
			t=query(1,cnt-x+1,cnt);
			cout<<t<<endl;
		}
	}
}
/*
2 100
A 96
Q 1

5 100
A 96
Q 1
A 97
Q 1
Q 2
*/