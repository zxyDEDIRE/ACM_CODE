#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int _l,_r,cnt0,cnt1;
};
struct Seg{
	int l,r,lazy;
	node val;
	void f()
	{
		lazy^=1;
		val._l^=1;
		val._r^=1;
		swap(val.cnt0,val.cnt1);
	}
}t[maxn<<2];
int n,q;
node add(node &a,node &b)
{
	node now;
	now._l=a._l;
	now._r=b._r;
	now.cnt0=a.cnt0+b.cnt0;
	now.cnt1=a.cnt1+b.cnt1;
	if(a._r==b._l)
	{
		if(a._r==0)now.cnt0++;
		else now.cnt1++;
	}
	return now;
}
void pushup(int rt)
{
	t[rt].val=add(t[rt<<1].val,t[rt<<1|1].val);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].f();
		t[rt<<1|1].f();
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r)
	{
		char ch;
		cin>>ch;
		t[rt].val._l=t[rt].val._r=(ch=='1');
		t[rt].val.cnt0=t[rt].val.cnt1=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].f();
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
node query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	node ans={-1,-1,-1,-1};
	if(l<=mid)
	{
		ans=query(rt<<1,l,r);
	}
	if(r>mid)
	{
		node now=query(rt<<1|1,l,r);
		if(ans._l==-1)ans=now;
		else ans=add(ans,now);
	}
	return ans;
}
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		char op;int l, r;
		cin>>op>>l>>r;
		if(op=='M')
		{
			update(1,l,r);
		}
		else
		{
			node now=query(1,l,r);
			cout<<max(now.cnt0,now.cnt1)+1<<endl;
		}
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
8 1
10001101
Q 1 3


4 3
1001
Q 1 4
M 4 4
Q 1 4
*/