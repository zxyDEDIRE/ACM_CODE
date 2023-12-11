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
const int maxn=2e5+100;
struct Seg{
	int l,r;ll val;
}t[maxn<<2];
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void build(int rt,int l,int r){
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		cin>>t[rt].val;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r){
	if(t[rt].val==(t[rt].r-t[rt].l+1))return ;
	if(t[rt].l==t[rt].r){
		t[rt].val=sqrt(t[rt].val);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
ll query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
int n;
void solve()
{
	int T=1;
	while(cin>>n)
	{
		cout<<"Case #"<<T<<":\n";
		build(1,1,n);
		int q;
		cin>>q;
		while(q--)
		{
			int op,x,y;
			cin>>op>>x>>y;
			if(x>y)swap(x,y);
			if(op==0)update(1,x,y);
			else cout<<query(1,x,y)<<endl;
		}
		T++;
		cout<<"\n";
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
Case #1:
19
7
6

Case #1:
19
7
6


*/