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
struct node{
	int l,r,val;
	node operator+(const node&a)const{
		node now;
		if(l==-1)return a;
		if(a.l==-1)return {l,r,val};
		now.l=l;now.r=a.r;now.val=val+a.val;
		if(r==a.l)now.val--;
		return now;
	}
};
struct Seg{
	int l,r,lazy;node val;
}t[maxn<<2];
vector<int>v[maxn];
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],id[maxn],di[maxn],tot;
int c[maxn];
void modfy(int rt,int k){
	t[rt].val.l=t[rt].val.r=k;
	t[rt].val.val=1;
	t[rt].lazy=k;
};
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void pushdown(int rt){
	if(t[rt].lazy)
	{
		modfy(rt<<1,t[rt].lazy);
		modfy(rt<<1|1,t[rt].lazy);
		t[rt].lazy=0;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r};
	if(l==r){
		t[rt].val.l=t[rt].val.r=c[di[l]];
		t[rt].val.val=1;
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k){
	if(l<=t[rt].l&&t[rt].r<=r){
		modfy(rt,k);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
node query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	node ans={-1,-1,-1};
	if(l<=mid)ans=ans+query(rt<<1,l,r);
	if(r>mid)ans=ans+query(rt<<1|1,l,r);
	return ans;
}



void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==son[x]||y==f[x])continue;
		dfs2(y,y);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
void upRange(int x,int y,int k)
{
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],k);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],k);
}
node qRange(int x,int y)
{
	node _x={-1,-1,-1};
	node _y={-1,-1,-1};
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y),swap(_x,_y);
		node now=query(1,id[top[x]],id[x]);
		_x=now+_x;
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y),swap(_x,_y);
	node now=query(1,id[x],id[y]);
	_y=now+_y;

	if(id[x]>id[y])swap(_x,_y);
	swap(_x.l,_x.r);
	return _x+_y;
}
int n,q;
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>c[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);

	while(q--)
	{
		char op;int x,y,w;
		cin>>op>>x>>y;
		if(op=='Q')
		{
			cout<<qRange(x,y).val<<endl;
		}
		else
		{
			cin>>w;
			upRange(x,y,w);
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
/*
11 3
1 2 1 2 2 1 2 2 2 2 1
1 2
2 3
3 4
4 5
5 10
10 11
3 6
6 8
6 7
7 9
Q 11 9
Q 11 8
Q 8 9
*/