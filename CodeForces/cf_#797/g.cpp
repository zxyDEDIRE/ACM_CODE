#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{
	int l,r,ma,num,lazy;
}t[maxn<<2];
bitset<maxn>vis;
int p[maxn];
int n,m;
void pushup(int rt)
{
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].num=t[rt<<1].num+t[rt<<1|1].num;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		if(vis[l])t[rt].ma=p[l],t[rt].num=1;
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
		t[rt<<1].ma=t[rt<<1|1].ma=t[rt<<1].num=t[rt<<1|1].num=0;
		t[rt<<1].lazy=t[rt<<1|1].lazy=1;
		t[rt].lazy=0;
	}
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].ma;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
inline void update(int rt,int l,int x)
{
	if(t[rt].l==t[rt].r&&t[rt].l==l)
	{
		t[rt].ma=x;
		t[rt].num=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)
	{
		if(t[rt<<1|1].ma>x)
		{
			t[rt<<1|1].ma=t[rt<<1|1].num=0;
			t[rt<<1|1].lazy=1;
		}
		update(rt<<1,l,x);
	}
	else
	{
		update(rt<<1|1,l,x);
	}
	pushup(rt);
}
void solve()
{
	cin>>n>>m;
	int tt=0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		cin>>p[i];
		if(p[i]<tt){
			vis[i]=1;
		}
		tt=min(tt,p[i]);
	}
	build(1,1,n);
	cout<<t[1].num<<endl;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		p[x]-=y;

		int s=query(1,x,n);
		cout<<x<<" "<<p[x]<<" "<<s<<endl;
		if(x<s)
		{
			update(1,x,p[x]);
		}
		cout<<t[1].num<<endl;
	}
}
/*
10 13 5 2 6
10 9 
*/
int main()
{
	solve();
}