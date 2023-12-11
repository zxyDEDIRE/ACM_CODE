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
	int l,r;ll val,lazy;
}t[maxn<<2];
ll ans[maxn<<2];
void f(int rt,ll k){
	t[rt].val+=k*(t[rt].r-t[rt].l+1);
	t[rt].lazy+=k;
}
void pushdown(int rt){
	if(t[rt].lazy)
	{
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
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
}
void dfs(int rt)
{
	if(t[rt].l==t[rt].r){
		ans[t[rt].l]=t[rt].val;
		return ;
	}
	pushdown(rt);
	dfs(rt<<1);
	dfs(rt<<1|1);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid){}
	if(r>mid){}
	return ans;
}

pp(3) p[maxn];
int q[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	vector<int>v(n*2+m);
	for(int i=1;i<=n;i++)
	{
		int a,b,c;
		cin>>a>>b>>c;
		p[i]={a,b,c};
		v[i*2-2]=a;
		v[i*2-1]=b;
	}
	for(int i=1;i<=m;i++){
		cin>>q[i];
		v[2*n+i-1]=q[i];
	}
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	int len=v.size();
	// for(int i=0;i<len;i++)
	// 	cout<<v[i]<<" ";cout<<endl;
	build(1,1,len);
	for(int i=1;i<=n;i++)
	{
		auto [a,b,c]=p[i];
		int l=lower_bound(v.begin(),v.end(),a)-v.begin()+1;
		int r=lower_bound(v.begin(),v.end(),b)-v.begin()+1;
		// cout<<l<<" "<<r<<" "<<c<<endl;
		update(1,l,r,c);
	}
	dfs(1);
	for(int i=1;i<=m;i++)
	{
		int x=lower_bound(v.begin(),v.end(),q[i])-v.begin()+1;
		cout<<ans[x]<<endl;
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
3 2
1 123 1
23 234 2
34 456 4
25
77
*/