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
}t[maxn<<2];
void f(int rt,int k){
	t[rt].val=k*(t[rt].r-t[rt].l+1);
	t[rt].lazy=k;
};
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void pushdown(int rt){
	if(t[rt].lazy>=0)
	{
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=-1;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r,1,-1};
	if(l==r){
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
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
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}


struct node{
	ll op,x,y;
}q[maxn];
vector<ll>p;
int n;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char op;
		ll x,y;
		cin>>op;
		if(op=='+')
		{
			cin>>x>>y;
			q[i]={0,x,y};
			p.push_back(x);
			p.push_back(y);
		}
		else if(op=='-')
		{
			cin>>x>>y;
			q[i]={1,x,y};
			p.push_back(x);
			p.push_back(y);
		}
		else
		{
			cin>>x;
			q[i]={-1,x};
			p.push_back(x);
		}
	}
	sort(p.begin(),p.end());
	p.erase(unique(p.begin(),p.end()),p.end());
	int len=p.size();
	build(1,1,len);
	for(int i=1;i<=n;i++)
	{
		auto [op,x,y]=q[i];
		x=lower_bound(p.begin(),p.end(),x)-p.begin()+1;
		y=lower_bound(p.begin(),p.end(),x)-p.begin()+1;
		if(op==0)
		{
			update(1,x,y,0);
		}
		else if(op==1)
		{
			update(1,x,y,1);
		}
		else
		{
			
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