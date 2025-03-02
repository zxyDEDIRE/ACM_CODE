#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
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
const int maxn=2e5+100;
struct Seg{
	int l,r;ll val,lazy;
}t[maxn<<2];
void f(int rt,int k){
	t[rt].val+=k*(t[rt].r-t[rt].l+1);
	t[rt].lazy+=k;
};
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void pushdown(int rt){
	if(t[rt].lazy)
	{
		f(rt<<1,t[rt].lazy);
		f(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
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
	pushup(rt);
}
ll query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	ll ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}



vector<int>v[maxn];
int dep_mi[maxn],dep_ma[maxn];
int id_d[maxn],indx;
int id_l[maxn];
int id[maxn];
int dep[maxn];
int siz[maxn];
int ma=0;
int n,q;
void init(){
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		dep[i]=id_l[i]=id_d[i]=id[i]=0;
		dep_mi[i]=INF;
		dep_ma[i]=0;
	}
	indx=0;
	ma=0;
}
void dfs1(int x)
{
	ma=max(ma,dep[x]);
	siz[x]=1;
	id_d[x]=++indx;
	for(auto y:v[x])
	{
		dep[y]=dep[x]+1;
		dfs1(y);
		siz[x]+=siz[y];
	}
}
void mark()
{
	queue<int>q;
	int now=0;
	q.push(1);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		id_l[x]=++now;
		int D=dep[x];
		dep_mi[D]=min(dep_mi[D],now);
		dep_ma[D]=max(dep_ma[D],now);
		for(auto y:v[x])
			q.push(y);
	}
}

void solve()
{
	cin>>n>>q;
	init();
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	dfs1(1);
	mark();
	build(1,1,n);
	for(int i=1;i<=n;i++)
		id[id_l[i]]=id_d[i];

	auto ql=[&](int l,int r,int x,int y)->int{
		if(id[l]>=x&&id[l]<=y)return l;
		int ans=l;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(id[mid]<=x)l=mid,ans=mid;
			else r=mid;
		}
		while(id[ans+1]<x)ans++;
		return ans+1;
	};

	auto qr=[&](int l,int r,int x,int y)->int{
		if(id[r]>=x&&id[r]<=y)return r;
		int ans=r;
		while(l<r-1)
		{
			int mid=(l+r)>>1;
			if(id[mid]>y)r=mid,ans=mid;
			else l=mid;
		}
		while(id[ans-1]>y)ans--;
		return ans-1;
	};
	


	// for(int i=1;i<=n;i++)
	// 	cout<<"id_l["<<i<<"]="<<id_l[i]<<endl;
	// cout<<endl;

	// for(int i=1;i<=n;i++)
	// 	cout<<"id_d["<<i<<"]="<<id_d[i]<<endl;
	// cout<<endl;

	// for(int i=1;i<=n;i++)
	// 	cout<<"id["<<i<<"]="<<id[i]<<endl;
	// cout<<endl;

	while(q--)
	{
		int x,k,w;
		cin>>x>>k>>w;
		int now=dep[x]+k;
		if(now>ma){
			cout<<0<<endl;
			continue;
		}
		int y=id_d[x]+siz[x]-1;
		x=id_d[x];
		if(id[dep_ma[now]]<x || id[dep_mi[now]]>y)
		{
			cout<<0<<endl;
			continue;
		}

		// cout<<"mi:"<<dep_mi[now]<<" ma:"<<dep_ma[now]<<endl;
		int l=ql(dep_mi[now],dep_ma[now],x,y);
		int r=qr(l,dep_ma[now],x,y);
		// cout<<"l:"<<l<<" r:"<<r<<endl;

		update(1,l,r,w);
		cout<<query(1,l,r)<<endl;
	
		
	}
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
/*
7 1
1 1 2 2 3 3
2 1 10

7 4
1 1 3 3 5 6
6 0 1000
5 1 100
3 2 10
1 3 1
*/