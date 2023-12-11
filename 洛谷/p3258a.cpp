#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct Seg{int l,r,val,lazy;}t[maxn<<1];
int dep[maxn],fa[maxn],siz[maxn],top[maxn],son[maxn];
int id[maxn],tot;
vector<int>v[maxn];
int ans[maxn];
int p[maxn];
int n;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=t[rt].lazy=0;
	if(l==r)return ;
	int m=(l+r)>>1;
	build(rt<<1,l,m);
	build(rt<<1|1,m+1,r);
}
void pushdown(int rt)
{
	t[rt<<1].lazy+=t[rt].lazy;
	t[rt<<1|1].lazy+=t[rt].lazy;

	t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
	t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);

	t[rt].lazy=0;
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=1;
		t[rt].val+=(t[rt].r-t[rt].l+1);
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l,r);
	else return query(rt<<1|1,l,r);
}
inline void upRange(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y]);
}
inline int qRange(int x){
	return query(1,id[x],id[x]);
}
void dfs1(int x,int f,int deep)
{
	dep[x]=deep;
	fa[x]=f;
	siz[x]=1;
	int maxson=-1;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson){
			maxson=siz[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	id[x]=++tot;
	top[x]=topf;
	if(!son[x])return ;
	dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	build(1,1,n);

	for(int i=1;i<n;i++){
		upRange(p[i],p[i+1]);
	}

	for(int i=1;i<=n;i++){
		int t=query(1,id[i],id[i]);
		if(i==p[1])cout<<t<<"\n";
		else cout<<t-1<<"\n";
	}
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;
//    cin>>__;
	__=1;
	while(__--)solve();
	return 0;
}