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
const int maxn=1e6;
struct Seg{
	int l,r,cnt,val,lazy;
}t[maxn<<2];
bitset<maxn>vis;
int v[maxn];
int n,d;
void pushup(int rt)
{
	t[rt].cnt=t[rt<<1].cnt+t[rt<<1|1].cnt;
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}

void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)return ;
	int mid=(t[rt].l+t[rt].r)/2;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
int cnt(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].cnt;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=cnt(rt<<1,l,r);
	if(r>mid)ans+=cnt(rt<<1|1,l,r);
	return ans;
}
int val(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	pushdown(rt);
	int ans=0;
	if(l<=mid)ans+=val(rt<<1,l,r);
	if(r>mid)ans+=val(rt<<1|1,l,r);
	return ans;
}
void update(int rt,int l,int c)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].cnt=c;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,c);
	else update(rt<<1|1,l,c);
	pushup(rt);
}
void change(int rt,int l,int r,int c)
{
	if(t[rt].l==t[rt].r)
	{
		t[rt].val+=c*(t[rt].r-t[rt].l+1);
		t[rt].lazy+=c;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)change(rt<<1,l,r,c);
	if(r>mid)change(rt<<1|1,l,r,c);
	pushup(rt);
}
void solve()
{
	cin>>n>>d;
	build(1,1,2e5);
	cout<<t[1].l<<" "<<t[1].r<<endl;
	ll ans=0;
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(!vis[x])
		{
			vis[x]=1;
			int cl=cnt(1,x-d,x-1);
			ans+=cl*(cl-1)/2;
			int cr=cnt(1,x+1,x+d);
			ans+=cr*(cr-1)/2;

			int X=val(1,x,x+d-1);
			ans+=X;
			ans-=cnt(1,x-d,x-1)*cnt(1,1,x);

			update(1,x,1);
			change(1,x,x+d-1,X-v[x]);
			v[x]=X;
		}
		else
		{
			vis[x]=1;
			int cl=cnt(1,x-d,x-1);
			ans-=cl*(cl-1)/2;
			int cr=cnt(1,x+1,x+d);
			ans-=cr*(cr-1)/2;

			int X=val(1,x,x+d);
			ans-=X;
			ans+=cnt(1,x-d,x-1)*cnt(1,1,x);

			update(1,x,0);
			change(1,x,x+d-1,X-v[x]);
			v[x]=X;
		}
		cout<<ans<<endl;
	}
}
int main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
()*(cnt[1,i+d]-cnt[1,x]);

cnt[1,x]+...+cnt[1,x+d];
x-d+d
x-1+d

1 5
1
*/