/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=50000+111;
struct node{
	int l,r,val,lazy;
}t[maxn<<2];
int p[maxn];
int n;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
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
void pushdown(int rt)
{
	t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
	t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
	t[rt<<1].lazy+=t[rt].lazy;
	t[rt<<1|1].lazy+=t[rt].lazy;
	t[rt].lazy=0;
}
void update(int rt,int l,int r,int c)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].val+=c*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=c;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,c);
	if(r>mid)update(rt<<1|1,l,r,c);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	string ch;
	int l,r,c;
	while(cin>>ch)
	{
		if(ch=="End")break;
		if(ch=="Add")
		{
			cin>>l>>c;
			update(1,l,l,c);
		}
		else if(ch=="Sub")
		{
			cin>>l>>c;
			update(1,l,l,-c);
		}
		else if(ch=="Query")
		{
			cin>>l>>r;
			cout<<query(1,l,r)<<endl;
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __,_;cin>>__;
	for(_=1;_<=__;_++){
		cout<<"Case "<<_<<":\n";
		solve();
	}
	return 0;
}