#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int l,r,val,lazy;
}t[maxn<<2];
vector<pii>v[maxn];
int f[maxn],dep[maxn],siz[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],tot;
int w[maxn];
int n,q;
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	if(l==r){
		t[rt].val=w[di[t[rt].l]];
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		t[rt<<1].val^=t[rt].lazy;
		t[rt<<1|1].val^=t[rt].lazy;
		t[rt<<1].lazy^=t[rt].lazy;
		t[rt<<1|1].lazy^=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		t[rt].val^=k;
		t[rt].lazy^=k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
}
int query(int rt,int l){
	if(t[rt].l==t[rt].r){
		return t[rt].val;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)return query(rt<<1,l);
	else return query(rt<<1|1,l);
}
void upRange(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],k);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],k);
}
void dfs1(int x,int fa)
{
	f[x]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
	son[x]=0;
	for(auto [y,c]:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto [y,c]:v[x])
		if(y!=son[x]&&y!=f[x])
			dfs2(y,y);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<n;i++){
		int x,y,c;
		cin>>x>>y>>c;
		w[x]^=c;
		w[y]^=c;
	}
	while(q--)
	{
		int op,x,y,c;
		cin>>op;
		if(op==1) 
		{
			cin>>x>>y>>c;
			w[x]^=c;
			w[y]^=c;
		}
		else if(op==2)
		{
			int x;cin>>x;
			cout<<w[x]<<endl;
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
/*
3 1
1 2 1
1 3 2
2 1

*/