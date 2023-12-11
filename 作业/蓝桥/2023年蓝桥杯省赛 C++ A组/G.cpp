/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
struct Seg{
	int l,r,val;
}t[maxn<<1];
struct edge{
	int to,next,w;
}edge[maxn];
struct E{
	int x,y,w;
}Edge[maxn];
int head[maxn],cnt;
int dep[maxn],f[maxn],siz[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],tot;
int w[maxn];
int p[maxn];
int n,m,q;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}

void pushup(int rt)
{
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
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
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int ans=INF;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int qRange(int x,int y)
{
	int ans=INF;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=min(ans,query(1,id[top[x]],id[x]));
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=min(ans,query(1,id[x],id[y]));
	return ans;
}



void dfs1(int x,int fa)
{
	siz[x]=1;
	f[x]=fa;
	dep[x]=dep[fa]+1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		dfs1(y,x);
		w[y]=edge[i].w;
		siz[x]+=siz[y];
		if(siz[son[x]]<siz[y])
			son[x]=y;
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		p[i]=i;
	for(int i=1;i<=m;i++)
	{
		auto &[x,y,w]=Edge[i];
		cin>>x>>y>>w;
	}
	sort(Edge+1,Edge+m+1,[&](E a,E b){
		return a.w>b.w;
	});
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=Edge[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			p[fa]=fb;
			add(x,y,w);
			add(y,x,w);
			// cout<<"EDGE "<<x<<" "<<y<<" "<<w<<endl;
		}
	}
	for(int i=1;i<=n;i++)
		if(!dep[i]){
			dfs1(i,i);
			dfs2(i,i);
		}
	build(1,1,n);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)!=find(y))cout<<-1<<endl;
		else
		{
			int lca=LCA(x,y);
			update(1,id[lca],INF);
			cout<<qRange(x,y)<<endl;
			update(1,id[lca],w[lca]);
		}
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
/*
5 4 1
1 2 5
2 3 6
3 4 1
1 4 3
2 4

1 2 5
2 3 6
3 4 1
*/