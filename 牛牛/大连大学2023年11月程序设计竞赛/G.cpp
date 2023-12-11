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
const int maxn=5e5+100;
struct Seg{
	int l,r,ma,mi,val;pii lazy;
}t[maxn<<2];
void f(int rt,pii k){
	t[rt].ma=max(t[rt].ma,k.second);
	t[rt].mi=min(t[rt].mi,k.first);
	t[rt].lazy.first=min(t[rt].lazy.first,k.first);
	t[rt].lazy.second=max(t[rt].lazy.second,k.second);
};
void pushup(int rt){
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
	t[rt].ma=max(t[rt<<1].ma,t[rt<<1|1].ma);
	t[rt].mi=min(t[rt<<1].mi,t[rt<<1|1].mi);
};
void pushdown(int rt){
	f(rt<<1,t[rt].lazy);
	f(rt<<1|1,t[rt].lazy);
};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	t[rt].lazy={INF,0};
	if(l==r){
		cin>>t[rt].val;
		t[rt].ma=t[rt].mi=l;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,pii k){
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
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
pii add(pii a,pii b)
{
	pii now;
	now.first=min(a.first,b.first);
	now.second=max(a.second,b.second);
	return now;
}
pii qq(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		return {t[rt].mi,t[rt].ma};
	}
	pushdown(rt);
	pii ans={INF,0};
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans=add(ans,qq(rt<<1,l,r));
	if(r>mid)ans=add(ans,qq(rt<<1|1,l,r));
	return ans;
}
int n,q;
void solve()
{
	cin>>n>>q;
	build(1,1,n);
	while(q--)
	{
		int op,l,r,x;
		cin>>op;
		if(op==1)
		{
			cin>>l>>r;
			pii now=qq(1,l,r);
			update(1,now.first,now.second,now);
		}
		else
		{
			cin>>x;
			pii now=qq(1,x,x);
			cout<<query(1,now.first,now.second)<<endl;
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
4 4
1 2 3 4
1 1 2
1 2 3
1 3 4
2 1 1
*/