#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll maxn=1e6;
ll n,T,p[maxn];
struct SegTreeNode{
	ll val;
	ll lazy;
}SegTree[maxn<<1];
void PushUp(ll rt)
{
	SegTree[rt].val=SegTree[rt<<1].val+SegTree[rt<<1|1].val;
}
void build(ll l,ll r,ll rt)
{
	SegTree[rt].lazy=0;
	if(l==r)
	{
		SegTree[rt].val=p[l];
		return ;
	}
	ll m=(l+r)/2;
	build(l,m,rt<<1);
	build(m+1,r,rt<<1|1);
	PushUp(rt);
}
void PushDown(ll rt,ll ln,ll rn)
{

	if(SegTree[rt].lazy)
	{
		SegTree[rt<<1].lazy+=SegTree[rt].lazy;
		SegTree[rt<<1|1].lazy+=SegTree[rt].lazy;
		SegTree[rt<<1].val+=SegTree[rt].lazy*ln;
		SegTree[rt<<1|1].val+=SegTree[rt].lazy*rn;
		
		SegTree[rt].lazy=0;
	}
}
void Update_qujian(ll L,ll R,ll C,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
	{
		SegTree[rt].val+=C*(r-l+1);
		SegTree[rt].lazy+=C;
		return ;
	}
	ll m=(l+r)>>1;
	PushDown(rt,m-l+1,r-m);
	if(L<=m)Update_qujian(L,R,C,l,m,rt<<1);
	if(R>m)Update_qujian(L,R,C,m+1,r,rt<<1|1);
	PushUp(rt);
}
ll Query(ll L,ll R,ll l,ll r,ll rt)
{
	if(L<=l&&r<=R)
		return SegTree[rt].val;//在区间直接返回 
	if(L>r||R<l)
		return 0;
	ll m=(l+r)>>1; 
	PushDown(rt,m-l+1,r-m);//下推之后，才准确查询子节点 
	return Query(L,R,l,m,rt<<1)+Query(L,R,m+1,r,rt<<1|1); 
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n>>T;
	for(ll i=1;i<=n;i++)cin>>p[i];


	build(1,n,1);

	ll fl;
	while(T--)
	{
		cin>>fl;
		ll x,y,k;
		if(fl==1)
		{
			cin>>x>>y>>k;//x到y之间加上k
			Update_qujian(x,y,k,1,n,1);
		}
		else if(fl==2)
		{
			cin>>x>>y;
			cout<<Query(x,y,1,n,1)<<endl;
		}
	}
}

