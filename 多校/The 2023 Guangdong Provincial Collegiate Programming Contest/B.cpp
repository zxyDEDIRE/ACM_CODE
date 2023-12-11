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
const ll INF=1e18+7;
const int maxn=1e6+100;

struct Seg{
	int l,r;ll val,lazy;
}t[maxn<<1];
pii p[maxn];
ll w[maxn];
int n,m;
struct ST{
	int f[maxn][30];
	void init()
	{
		for(int i=1;i<=n;i++)//距离为0初始化 
			f[i][0]=w[i];
		int t=log(n)/log(2)+1;//j定位 
		for(int j=1;j<t;j++)
		{
			for(int i=1;i<=n-(1<<j)+1;i++)
			{
				f[i][j]=min(f[i][j-1],f[i+(1<<(j-1))][j-1]);
				//f[i][j-1]为f[i][j]的长为2^j-1的前半段，另一段为f[i+(1<<(j-1))][j-1] 
			}
		} 
	}
	int query(int l,int r)
	{
		int k=log2(r-l+1);
		return min(f[l][k],f[r-(1<<k)+1][k]);
	}
}st;
void pushup(int rt)
{
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,INF};
	if(l==r){
		t[rt].val=w[l];
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
		t[rt<<1].val=t[rt].lazy+st.query(t[rt<<1].l,t[rt<<1].r);
		t[rt<<1|1].val=t[rt].lazy+st.query(t[rt<<1|1].l,t[rt<<1|1].r);
		t[rt<<1].lazy=t[rt].lazy;
		t[rt<<1|1].lazy=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,ll k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val=k+st.query(t[rt].l,t[rt].r);
		t[rt].lazy=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	cin>>m;
	for(int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	sort(p+1,p+1+m);
	build(1,1,n);

	st.init();
	for(int i=2;i<=m;i++)
	{
		auto [l,r]=p[i];
		auto [_l,_r]=p[i-1];
		if(r>_r)
		{
			int upl=max(l,_r+1);
			int upr=r;
			ll qans=query(1,_l,_r);
			update(1,upl,upr,qans);
		}
	}
	cout<<query(1,p[m].first,p[m].second)<<endl;
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