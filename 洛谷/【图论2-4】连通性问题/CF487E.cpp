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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{int l,r,val;};
struct Edge{int to,next;}edge[maxn];
vector<int>head,dfn,low,w;
vector<int>siz,dep,son,f,top,di,id;
vector<multiset<int>>T;
vector<vector<int>>v;
vector<node>t;
stack<int>s;
int cnt=0,indx,tot,id_cnt;
int n,m,q;
void add(int from,int to){
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	siz.resize(n*2+1);
	dep.resize(n*2+1);
	son.resize(n*2+1);
	f.resize(n*2+1);
	top.resize(n*2+1);
	id.resize(n*2+1);
	di.resize(n*2+1);

	w.resize(n+1);
	t.resize(n*8+1);
	T.resize(n+1);
	dfn.resize(n+1);
	low.resize(n+1);
	head.resize(n+1);
	v.resize(n*2+1);
	cnt=1;
	indx=0;
	tot=n;
	id_cnt=0;
}
void tarjan(int x,int fa=0)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				++tot;
				v[tot].push_back(x);
				v[x].push_back(tot);
				int u;
				do{
					u=s.top();s.pop();
					v[u].push_back(tot);
					v[tot].push_back(u);
				}while(u!=y);
			}
		}
		else if(i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
}
void pushup(int rt)
{
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,INF};
	if(l==r){
		int x=di[l];
		if(x>n)t[rt].val=*T[x-n].begin();
		else t[rt].val=w[x];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r,int k)
{
	if(t[rt].l==t[rt].r){
		t[rt].val=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
void dfs1(int x,int fa)
{
	if(x<=n&&fa>n)
		T[fa-n].insert(w[x]);
	f[x]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
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
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++id_cnt;
	di[id_cnt]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
		if(y!=son[x]&&y!=f[x])
			dfs2(y,y);
}
int lca(int x,int y)
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
void solve()
{
	cin>>n>>m>>q;
	init();
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,tot);
	while(q--)
	{
		char op;int x,y;
		cin>>op>>x>>y;
		if(op=='C')
		{
			if(w[x]!=y)update(1,id[x],id[x],y);
			int Q=w[x];
			w[x]=y;
			x=f[x];
			if(x<=n)continue;
			int pre=*T[x-n].begin();
			T[x-n].erase(T[x-n].find(Q));
			T[x-n].insert(y);
			int suf=*T[x-n].begin();
			if(pre!=suf)
				update(1,id[x],id[x],suf);
		}
		else
		{
			int now=lca(x,y);
			int ans=qRange(x,y);
			if(now>n)ans=min(ans,w[f[now]]);
			cout<<ans<<endl;
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
9 9 2
2
1
8
7
7
6
7
8
10
2 1
1 7
3 2
4 3
5 4
5 6
6 7
4 8
2 9
C 2 4
A 4 3
*/