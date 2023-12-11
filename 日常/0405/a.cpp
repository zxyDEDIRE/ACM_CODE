#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
int p[maxn];
int c[maxn];
int n,q,ans;
struct Seg{
	int l,r,val;
}S[maxn],t[maxn];


void build(int rt,int l,int r)
{
	t[rt].l=S[rt].l=l;
	t[rt].r=S[rt].r=r;
	t[rt].val=S[rt].val=0;
	if(l==r)return ;
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void update(int rt,int x)
{
	if(S[rt].l==S[rt].r)
	{
		S[rt].val=1;
		return ;
	}
	int m=(S[rt].l+S[rt].r)>>1;
	if(x<=m)
	{
		ans+=S[rt<<1|1].val;
		update(rt<<1,x);
	}
	else update(rt<<1|1,x);
	S[rt].val=S[rt<<1].val+S[rt<<1|1].val;
}
void add(int rt,int x)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val+=x;
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	if(x<=m)add(rt<<1,x);
	else add(rt<<1|1,x);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}

void cut(int rt,int x)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val-=x;
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	if(x<=m)cut(rt<<1,x);
	else cut(rt<<1|1,x);
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}





int main()
{
	ios::sync_with_stdio(false);
	cin.tie();cout.tie(0);

	cin>>n>>q;
	build(1,1,n);
	for(int i=1;i<=n;i++){
		cin>>p[i];
		ans=0;
		update(1,p[i]);
		c[i]=ans;
		add(1,c[i]);
	}
	while(q--)
	{
		int fl,x;
		cin>>fl>>x;
		if(fl==1)
		{
			if(p[x]>p[x+1])
			{
				swap(p[x],p[x+1]);
				cut(1,c[x+1]);
				c[x+1]--;
				if(c[x+1])add(1,c[x+1]);
			}
			else
			{
			}
		}
		else
		{

		}
	}
}