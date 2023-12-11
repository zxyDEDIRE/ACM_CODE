#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false);cout.tie(0);cout.tie(0);
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int N=32010;
const int maxn=1e6;
struct node{int x,y,id;}p[maxn];
struct Seg{
	int l,r,val;
}t[maxn<<1];
int ans[maxn];
int n;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l)
{
	if(t[rt].l==t[rt].r&&t[rt].l==l)
	{
		t[rt].val++;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
int main()
{	ios
	
	cin>>n;
	build(1,0,N);
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].y;
		update(1,p[i].x);
		int x=query(1,0,p[i].x);
		ans[x-1]++;
	}
	for(int i=0;i<n;i++)
		cout<<ans[i]<<"\n";
	
}