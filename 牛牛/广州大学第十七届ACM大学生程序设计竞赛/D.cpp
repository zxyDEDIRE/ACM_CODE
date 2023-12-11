/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{int x,y,w;}a[maxn];
struct Seg{int l,r,val;}t[maxn<<2];
int dep[maxn],fa[maxn],son[maxn],siz[maxn],indx;
int id[maxn],di[maxn],top[maxn],tot;
vector<pii>v[maxn];
int pre[maxn];
int w[maxn];
int p[maxn];
int n,m,q;
int find(int r){return p[r]=p[r]==r?p[r]:find(p[r]);}
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x]=f;
	siz[x]=1;
	son[x]=0;
	for(auto [y,c]:v[x])
	{
		if(y==f)continue;
		w[y]=c;
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
	{
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void pushup(int rt){
	t[rt].val=max(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r){
	t[rt]={l,r,0};
	if(l==r){
		t[rt].val=w[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int k){
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans=max(ans,query(rt<<1,l,r));
	if(r>mid)ans=max(ans,query(rt<<1|1,l,r));
	return ans;
}
int LCA(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int qRange(int x,int y){
	int lca=LCA(x,y);
	int now=query(1,id[lca],id[lca]);
	update(1,id[lca],0);
	int ans=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=max(ans,query(1,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=max(ans,query(1,id[x],id[y]));
	update(1,id[lca],now);
	return ans;
}
void init(){
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=a[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb){
			p[fa]=fb;
			v[x].push_back({y,w});
			v[y].push_back({x,w});
		}
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	for(int i=2;i<=n;i++)
		pre[i]=pre[i-1]+qRange(i-1,i);
}

void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		auto &[x,y,w]=a[i];
		cin>>x>>y>>w;
	}
	init();
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		cout<<pre[r]-pre[l]<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}