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
	int l,r;ll val;
}t[maxn<<2];
ll p[maxn];
int n;
// void f(int rt){};
void pushup(int rt){
	t[rt].val=(t[rt<<1].val|t[rt<<1|1].val);
};
void pushdown(int rt){};
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=max(0ll,p[l]);
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
}
ll query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid){ans|=query(rt<<1,l,r);}
	if(r>mid){ans|=query(rt<<1|1,l,r);}
	return ans;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	int q;cin>>q;
	build(1,1,n);
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<query(1,l,r)<<endl;
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