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
int p[maxn];
int n;
struct Seg{
	int l,r,_l,_r,lazy,val;
}t[maxn<<2];
void f(int rt,int k){
	t[rt]._l+=k;
	t[rt]._r+=k;
	t[rt].lazy+=k;
};
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val+abs(t[rt<<1]._r-t[rt<<1|1]._l);
	t[rt]._l=t[rt<<1]._l;
	t[rt]._r=t[rt<<1|1]._r;
};
void pushdown(int rt){
	if(t[rt].lazy)
	{
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=0;
		t[rt]._l=t[rt]._r=p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		f(rt,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
Seg add(Seg a,Seg b){
	Seg now;
	if(a.l!=-1&&b.l!=-1)
	{
		now.val=a.val+b.val+abs(a._r-b._l);
		now._l=a._l;
		now._r=b._r;
	}
	else if(a.l!=-1)
		now=a;
	else 
		now=b;
	return now;
}
int query1(int rt,int l)
{
	if(t[rt].l==t[rt].r)
		return t[rt]._l;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query1(rt<<1,l);
	else return query1(rt<<1|1,l);
}
Seg query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt];
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	Seg ans; ans.l=-1;
	if(l<=mid)ans=add(ans,query(rt<<1,l,r));
	if(r>mid)ans=add(ans,query(rt<<1|1,l,r));
	return ans;
}
void solve()
{
	int q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	// cout<<query(1,1,5).val<<endl;
	while(q--)
	{
		int op,l,r;
		cin>>op>>l>>r; 
		if(op==1)
		{
			int ans=query1(1,l)+query(1,l,r).val;
			cout<<ans<<endl;
		}
		else
		{
			update(1,l,r,1);
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