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
	int len;
	int l1,l2,r2,r1;
	int ok;
	node operator+(const node&b){
		node now;
		return now;
	}
	node operator+=(const int&a){
		node now;
		return now;
	}
};
struct Seg{
	int l,r,lazy;
	node val;
}t[maxn];
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r){
		char ch;cin>>ch;
		t[rt].val.l1=t[rt].val.l2=t[rt].val.r1=t[rt].val.r2=ch-'a';
		t[rt].val.len=1;
		t[rt].val.ok=0;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val+=t[rt].lazy;
		t[rt<<1|1].val+=t[rt].lazy;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val+=k;
		t[rt].lazy+=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
node query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	node ans,x;
	if(l<=mid)ans=query(rt<<1,l,r);
	if(r>mid){
		x=query(rt<<1|1,l,r);
		if(l<=mid)ans=ans+x;
		else ans=x;
	}
	return ans;
}
void solve()
{
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}