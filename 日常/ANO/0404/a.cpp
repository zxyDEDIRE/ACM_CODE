#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e5;
struct node{
	int l,r,val;
}t[maxn<<2];
int a[maxn];
int p[maxn];
int n,ans;

void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)return ;
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void update(int rt,int x)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val=1;
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;

	if(x<=m)
	{
		ans+=t[rt<<1|1].val;
		update(rt<<1,x);
	}
	else
	{
		update(rt<<1|1,x);
	}
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	cin>>n;

	build(1,1,n);

	for(int i=1;i<=n;i++)
	{
		cin>>p[i];
		update(1,p[i]);
		cout<<ans<<endl;
	}
}