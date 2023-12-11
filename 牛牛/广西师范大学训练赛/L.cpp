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
int c[maxn];
int di[maxn],id[maxn];
void ff(int rt){
	t[rt].lazy^=1;
	t[rt].val=(t[rt].r-t[rt].l+1-t[rt].val);
};
void pushup(int rt){
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
};
void pushdown(int rt){
	if(t[rt].lazy)
	{
		ff(rt<<1);
		ff(rt<<1|1);
		t[rt].lazy=0;
	}
};
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	if(l==r){
		t[rt].val=c[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		ff(rt);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
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


vector<int>v[maxn];
int f[maxn],son[maxn],dep[maxn],siz[maxn],top[maxn],tot;
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
inline int qSon(int x){
	return query(1,id[x],id[x]+siz[x]-1);
}
inline void upSon(int x){
	update(1,id[x],id[x]+siz[x]-1);
}
int n;
void solve()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	int m;
	cin>>m;
	while(m--)
	{
		string op;
		int x;
		cin>>op>>x;
		if(op=="get"){
			cout<<qSon(x)<<endl;
		}else{
			upSon(x);
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
4
1 1 1
1 0 0 1
3
pow 1
get 3
get 2
*/