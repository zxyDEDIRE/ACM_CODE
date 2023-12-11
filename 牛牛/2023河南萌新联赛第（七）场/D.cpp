#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int n,m;
void pushup(int rt){
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void pushdown(int rt){
	if(t[rt].lazy!=0)
	{
		t[rt<<1].val+=t[rt].lazy;
		t[rt<<1|1].val+=t[rt].lazy;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	if(l==r){
		cin>>t[rt].val;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int ans=INF;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void update(int rt,int l,int r,int w)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val-=w;
		t[rt].lazy-=w;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,w);
	if(r>mid)update(rt<<1|1,l,r,w);
	pushup(rt);
}
void solve()
{
	cin>>n>>m;
	build(1,1,n);
	for(int i=1;i<=m;i++)
	{
		int w,l,r;
		cin>>w>>l>>r;
		int c=query(1,l,r);
		if(c<w){
			cout<<-1<<endl;
			cout<<i<<endl;
			return ;
		}
		update(1,l,r,w);
	}
	cout<<0<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}