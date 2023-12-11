#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<ll,ll>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const ll INF=1e18+7;
const int maxn=1e6+100;
ll pre[maxn];
ll b[maxn];
int n;
namespace S{
	struct node{
		int l,r;
		pii val;
	}t[maxn];
	pii max(pii a,pii b)
	{
		if(a.first==b.first)
		{
			if(a.second>b.second)return a;
			else return b;
		}
		else if(a.first>b.first)return a;
		else return b;
	}
	void pushup(int rt)
	{
		t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
	}
	void build(int rt,int l,int r)
	{
		t[rt]={l,r,{-INF,0}};
		if(l==r){
			t[rt].val={pre[l],l};
			return ;
		}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	pii query(int rt,int l,int r)
	{
		if(l<=t[rt].l&&t[rt].r<=r)
			return t[rt].val;
		pii ans={-INF,0};
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)ans=max(ans,query(rt<<1,l,r));
		if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
		return ans;
	}
};
namespace Seg{
	struct seg{
		int l,r,val,lazy;
	}t[maxn];

	void pushup(int rt){
		t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
	}
	void pushdown(int rt){
		if(t[rt].lazy)
		{
			t[rt<<1].val-=t[rt].lazy;
			t[rt<<1|1].val-=t[rt].lazy;
			t[rt<<1].lazy+=t[rt].lazy;
			t[rt<<1|1].lazy+=t[rt].lazy;
			t[rt].lazy=0;
		}
	}
	void build(int rt,int l,int r){
		t[rt]={l,r,0,0};
		if(l==r){
			t[rt].val=b[l];
			return ;
		}
		int mid=(l+r)>>1;
		build(rt<<1,l,mid);
		build(rt<<1|1,mid+1,r);
		pushup(rt);
	}
	void update(int rt,int l,int r){
		if(l<=t[rt].l&&t[rt].r<=r){
			t[rt].val--;
			t[rt].lazy++;
			return ;
		}
		pushdown(rt);
		int mid=(t[rt].l+t[rt].r)>>1;
		if(l<=mid)update(rt<<1,l,r);
		if(r>mid)update(rt<<1|1,l,r);
		pushup(rt);
	}
	int query(int rt)
	{
		if(t[rt].l==t[rt].r)
			return t[rt].l;
		pushdown(rt);
		if(t[rt<<1|1].val>0)return query(rt<<1|1);
		else if(t[rt<<1].val>0)return query(rt<<1);
		else return 0;
	}
};

void solve()
{
	cin>>n;
	b[0]=INF;pre[0]=0;
	for(int i=1,x;i<=n;i++){
		cin>>x;
		pre[i]=pre[i-1]+x;

	}
	for(int i=1;i<=n;i++){
		cin>>b[i];
		b[i]=min(b[i],b[i-1]);
	}
	S::build(1,1,n);
	Seg::build(1,1,n);
	int l=1,r=n;
	ll ans=0;
	for(int t=1;t<=b[1];t++)
	{
		pii now=S::query(1,l,r);
		ans+=now.first;
		Seg::update(1,1,n);
		r=Seg::query(1);
	}
	cout<<b[1]<<" "<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
/*
1
4
-1 1 -1 -1
4 4 4 4


1
4
1 4 -3 3
4 3 2 1 



12 1
*/