#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Seg{int l,r,mi,ma;}t[maxn<<2];
int p[maxn];
int n,q;
void pushup(int rt)
{
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].mi=t[rt].ma=p[l];
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}Z
pii query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return {t[rt].mi,t[rt].ma};
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pii ans={INF,-INF};
	if(l<=mid)
	{
		pii a=query(rt<<1,l,r);
		ans.first=min(ans.first,a.first);
		ans.second=max(ans.second,a.second);
	}
	if(r>mid)
	{
		pii b=query(rt<<1|1,l,r);
		ans.first=min(ans.first,b.first);
		ans.second=max(ans.second,b.second);
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		pii ans=query(1,x,y);
		cout<<ans.second-ans.first<<endl;
	}
}