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
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];
int p[maxn];
void f(int rt,int k){
	t[rt].val+=k;
	t[rt].lazy+=k;
};
void pushup(int rt){
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
};
void pushdown(int rt){
	if(t[rt].lazy!=0)
	{
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=p[l];
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
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	build(1,1,n);
	for(int i=2;i<=n;i++)
		update(1,i,n,1);

	ll ans=1e18;
	for(int i=1;i<=n;i++)
	{
		int len_l=i-1;
		int len_r=n-i;
		ll now=p[i];
		if(i>1)now=max(now,1ll*query(1,1,i-1)+len_r);
		if(i<n)now=max(now,1ll*query(1,i+1,n)+len_l);
		// cout<<len_r<<" "<<len_l<<endl;
		// cout<<query(1,1,i-1)<<" "<<1ll*query(1,i+1,n)<<endl;
		// cout<<i<<" "<<now<<endl;
		ans=min(ans,now);
		// cout<<endl;


		if(i+1<=n)
		update(1,i+1,n,-1);
		update(1,1,i,1);
	}
	cout<<ans<<endl;

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
2 1 5 6 4 3
2 1 0 1 2 3
*/