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
	int l,r,val,lazy,cnt;
}t[maxn<<2];
vector<int>v[maxn];
int n;
void pushup(int rt)
{
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
	t[rt].cnt=0;
	if(t[rt<<1].val==t[rt].val)
		t[rt].cnt+=t[rt<<1].cnt;
	if(t[rt<<1|1].val==t[rt].val)
		t[rt].cnt+=t[rt<<1|1].cnt;
}
void f(int rt,int val)
{
	t[rt].val+=val;
	t[rt].lazy+=val;
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
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r){
		v[l].clear();
		t[rt].cnt=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int val)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		f(rt,val);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,val);
	if(r>mid)update(rt<<1|1,l,r,val);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(t[rt].val==1)return t[rt].cnt;
		else return 0;
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
	build(1,1,n);
	for(int i=1;i<n;i++)
	{
		int x,y;cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		update(1,1,i,1);
		for(auto y:v[i])
			if(y<i)
				update(1,1,y,-1);
		ans+=query(1,1,i);
	}
	cout<<ans<<endl;
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