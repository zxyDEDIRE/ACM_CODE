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
	int l,r,v0,v1,lazy;
}t[maxn];
char s[maxn];
int p[maxn];
int n;
void pushup(int rt)
{
	t[rt].v0=(t[rt<<1].v0^t[rt<<1|1].v0);
	t[rt].v1=(t[rt<<1].v1^t[rt<<1|1].v1);
}
void f(int rt)
{
	swap(t[rt].v0,t[rt].v1);
	t[rt].lazy^=1;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		f(rt<<1);
		f(rt<<1|1);
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0,0};
	if(l==r){
		if(s[l]=='1')t[rt].v1=p[l];
		else t[rt].v0=p[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		f(rt);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l,int r,int op){
	if(l<=t[rt].l&&t[rt].r<=r){
		if(op==0)return t[rt].v0;
		else return t[rt].v1;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans^=query(rt<<1,l,r,op);
	if(r>mid)ans^=query(rt<<1|1,l,r,op);
	return ans;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
		cin>>s[i];
	build(1,1,n);
	int q;cin>>q;
	while(q--)
	{
		int op,l,r;
		cin>>op;
		if(op==1)
		{
			cin>>l>>r;
			update(1,l,r);
		}
		else
		{
			cin>>l;
			cout<<query(1,1,n,l)<<" ";
		}
	}
	cout<<endl;
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