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
	int l,r,lazy,sum,mi,ma;
	Seg(){
		l=r=0;
		lazy=1;
		sum=0;
		mi=INF;
		ma=-INF;
	}
	// Seg operator+(const Seg&a)const{
	// 	Seg now;
	// 	cout<<l<<" "<<a.r<<endl;
	// 	now.l=l; now.r=a.r; now.lazy=1;
	// 	now.sum=sum+a.sum;
	// 	now.mi=min(mi,a.mi);
	// 	now.ma=max(ma,a.ma);
	// 	return now;
	// }
}t[maxn<<2];
Seg add(Seg a, Seg b)
{
	Seg now;
	now.l=a.l; now.r=b.r; now.lazy=1;
	now.sum=a.sum+b.sum;
	now.mi=min(a.mi,b.mi);
	now.ma=max(a.ma,b.ma);
	return now;
}
int c[maxn],di[maxn];
void modify(int rt,int k){
	t[rt].sum*=k;
	swap(t[rt].mi,t[rt].ma);
	t[rt].mi*=k;
	t[rt].ma*=k;
	t[rt].lazy*=k;
};
void pushup(int rt){
	// t[rt]=t[rt<<1]+t[rt<<1|1];
	t[rt]=add(t[rt<<1],t[rt<<1|1]);
};
void pushdown(int rt){
	if(t[rt].lazy!=1)
	{
		modify(rt<<1,-1);
		modify(rt<<1|1,-1);
		t[rt].lazy=1;
	}
};
void build(int rt,int l,int r){
	if(l==r){
		t[rt].l=l;
		t[rt].r=r;
		t[rt].lazy=1;
		t[rt].sum=t[rt].ma=t[rt].mi=c[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update1(int rt,int l,int w){
	if(t[rt].l==t[rt].r){
		t[rt].sum=w;
		t[rt].ma=w;
		t[rt].mi=w;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update1(rt<<1,l,w);
	else update1(rt<<1|1,l,w);
	pushup(rt);
}
void update2(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		modify(rt,-1);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update2(rt<<1,l,r);
	if(r>mid)update2(rt<<1|1,l,r);
	pushup(rt);
}
Seg query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt];
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	Seg ans=Seg();
	if(l<=mid)ans=add(ans,query(rt<<1,l,r));
	if(r>mid)ans=add(ans,query(rt<<1|1,l,r));
	return ans;
}


vector<pp(3)>v[maxn];
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],id[maxn],tot;
pii p[maxn];
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(auto [y,w,_id]:v[x])
	{
		if(y==fa)continue;
		c[y]=w;
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
	for(auto [y,w,_id]:v[x])
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
void upRange(int x,int y)
{
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update2(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		update2(1,id[son[x]],id[y]);
}
Seg qRange(int x,int y)
{
	Seg ans=Seg();
	while(top[x]!=top[y])//不同链
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=add(ans,query(1,id[top[x]],id[x]));
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(x!=y)
		ans=add(ans,query(1,id[son[x]],id[y]));
	return ans;
}

int n,m;
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;++x,++y;
		v[x].push_back({y,w,i});
		v[y].push_back({x,w,i});
		p[i]={x,y};
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	cin>>m;
	while(m--)
	{
		string op;
		int i,x,y,w;
		cin>>op;
		if(op=="C")
		{
			cin>>i>>w;
			auto [x,y]=p[i];
			if(dep[x]<dep[y])swap(x,y);
			update1(1,id[x],w);
		}
		else if(op=="N")
		{
			cin>>x>>y;x++;y++;
			upRange(x,y);
		}
		else if(op=="SUM")
		{
			cin>>x>>y;x++,y++;
			Seg now=qRange(x,y);
			cout<<now.sum<<endl;
		}
		else if(op=="MAX")
		{
			cin>>x>>y;x++,y++;
			Seg now=qRange(x,y);
			cout<<now.ma<<endl;
		}
		else if(op=="MIN")
		{
			cin>>x>>y;x++,y++;
			Seg now=qRange(x,y);
			cout<<now.mi<<endl;
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
3
0 1 1
1 2 2
8
SUM 0 2 	3
MAX 0 2 	2
N 0 1 	    
SUM 0 2 	1
MIN 0 2 	-1
C 1 3  
SUM 0 2 	5
MAX 0 2  	3



3
0 1 1
1 2 2
3
N 0 1
C 1 3
SUM 0 2


7
0 1 1
0 2 -1
1 3 2
1 4 3
2 5 -2
2 6 4
8
SUM 3 6
MIN 3 6
MAX 3 6
N 3 6
SUM 3 6
MIN 3 6
MAX 3 6
SUM 0 5
*/