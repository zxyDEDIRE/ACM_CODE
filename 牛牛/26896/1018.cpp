#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{
	int l,r,val;
}t[maxn];
int n,x,ans;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(t[rt].l+t[rt].r)>>1;
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
	if(l<=mid)
	{
		ans+=t[rt<<1|1].val;
		update(rt<<1,l);
	}
	else
	{
		update(rt<<1|1,l);
	}
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
signed main()
{
	cin>>n;
	build(1,1,100000);

	for(int i=1;i<=n;i++)
	{
		cin>>x;
		update(1,x);
	}
	cout<<ans<<endl;
}