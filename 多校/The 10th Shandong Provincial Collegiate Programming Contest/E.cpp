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
}t[maxn<<2],T[maxn<<2];
int p[maxn];
int n;
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	T[rt]={l,r,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void f(int rt,int k){
	t[rt].val+=k*(t[rt].r-t[rt].l+1);
	t[rt].lazy+=k;
}
void pushup(int rt)
{
	T[rt].val=T[rt<<1].val+T[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		f(rt,1);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
}
void update(int rt,int l,int r,int k)
{
	if(t[rt].l==t[rt].r){
		T[rt].val+=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l>r)return 0;
	if(l<=T[rt].l&&T[rt].r<=r)
		return T[rt].val;
	int mid=(T[rt].l+T[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void dfs(int rt)
{
	if(t[rt].l==t[rt].r){
		// cout<<t[rt].val<<" ";
		cout<<t[rt].val;
		if(t[rt].l!=n)cout<<" ";
		return ;
	}
	pushdown(rt);
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		p[i]=0;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(p[x])
		{
			int len=query(1,p[x]+1,i-1);
			update(1,p[x],p[x],-1);
			update(1,i,i,1);
			if(len>=1)update(1,1,len);
		}
		else update(1,1,n),update(1,i,i,1);
		p[x]=i;
	}
	dfs(1);
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--){
		solve();
		if(__)cout<<endl;
	}
	return 0;
}
/*
4 3 4 
4 3 2 4
1 2 3 4
*/