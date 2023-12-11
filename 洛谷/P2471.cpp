#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{int l,r,val;}t[maxn<<2];
int a[maxn],p[maxn];
map<int,int>mp;
int n,m;
void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
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
int solve(int x,int y)
{
	int xx=mp[x];
	int yy=mp[y];
	int a=p[xx];
	int b=p[yy];
	if(xx==0&&yy==0)return 2;
	else if(xx==0&&yy!=0)
	{
		int z=lower_bound(a+1,a+1+n,xx)-a;
		int c=query(1,z,yy-1);
		if(c<b)return 2;
		else return 0;
	}
	else if(xx!=0&&yy==0)
	{
		int z=lower_bound(a+1,a+1+n,yy)-a;
		int c=query(1,xx+1,z-1);
		if(c<a)return 2;
		else return 0;
	}
	return 1;
}
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++){
		int x,y;
		cin>>a[i]>>p[i];
		mp[a[i]]=i;
	}
	build(1,1,n);

	cin>>m;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		int t=solve(x,y);
		if(t==1)cout<<"true\n";
		else if(t==0)cout<<"false\n";
		else if(t==2)cout<<"maybe\n";
	}
}