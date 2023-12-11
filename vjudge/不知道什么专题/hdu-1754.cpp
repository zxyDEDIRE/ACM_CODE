/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<bitset>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn=1e6;
ll p[maxn];
int n,T;
struct Seg{
	ll l,r,val,lazy;
}t[maxn<<1];
void pushup(int rt)
{
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].lazy=0;
	if(l==r)
	{
		t[rt].val=p[l];
		return ;
	}
	int m=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int m=(t[rt].l+t[rt].r)>>1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;

		t[rt<<1].val+=(m-t[rt].l+1)*t[rt].lazy;
		t[rt<<1|1].val+=(t[rt].r-m)*t[rt].lazy;

		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val=k;
		return ;
	}
	//pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)	update(rt<<1,l,r,k);
	if(r>m)	update(rt<<1|1,l,r,k);
	pushup(rt);
}
ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	//pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	ll ans1=0,ans2=0;

	if(l<=m)ans1=query(rt<<1,l,r);
	if(r>m)ans2=query(rt<<1|1,l,r);

	return max(ans1,ans2);

}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);


	while(cin>>n>>T)
	{
		for(int i=1;i<=n;i++)
			cin>>p[i];

		build(1,1,n);

		while(T--)
		{
			string fl;
			int x,y,k;
			cin>>fl;
			if(fl=="U")
			{
				cin>>x>>k;
				update(1,x,x,k);
			}
			else if(fl=="Q")
			{
				cin>>x>>y;
				cout<<query(1,x,y)<<"\n";
			}
		}
	}
	
}