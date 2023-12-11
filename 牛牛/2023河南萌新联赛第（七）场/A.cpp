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
	int l,r,a,b,w;
}t[maxn<<2];
int n,m;
void pushup(int rt)
{
	t[rt].a=t[rt<<1].a+t[rt<<1|1].a;
	t[rt].b=t[rt<<1].b+t[rt<<1|1].b;
}
void pushdown(int rt)
{
	if(t[rt].w)
	{
		t[rt<<1].w^=1;
		t[rt<<1|1].w^=1;
		swap(t[rt<<1].a,t[rt<<1].b);
		swap(t[rt<<1|1].a,t[rt<<1|1].b);
		t[rt].w=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0,0};
	if(l==r){
		char ch;
		cin>>ch;
		if(ch=='1')t[rt].a++;
		else t[rt].b++;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		swap(t[rt].a,t[rt].b);
		t[rt].w^=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].a;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void solve()
{
	cin>>n>>m;
	build(1,1,n);
	while(m--)
	{
		int op,l,r;
		cin>>op>>l>>r;
		if(op==1)
		{
			cout<<query(1,l,r)<<endl;
		}
		else
		{
			update(1,l,r);
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