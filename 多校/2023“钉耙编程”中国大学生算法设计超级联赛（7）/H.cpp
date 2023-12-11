/*！*/
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
	int l,r,a,b;
}t[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
int siz[maxn],son[maxn],dep[maxn],f[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int a[maxn];
int b[maxn];
vector<int>rt;
int maxdep;
int n,S,T;
void init(){
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		a[i]=b[i]=0;
	}
	vis.reset();
	tot=0;
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,int op)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		if(op==1)t[rt].a=1;
		else t[rt].b=1;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,op);
	if(r>mid)update(rt<<1|1,l,r,op);
}
void pushdown(int rt)
{
	if(t[rt].l==t[rt].r){
		a[di[t[rt].l]]=t[rt].a;
		b[di[t[rt].l]]=t[rt].b;
		return ;
	}
	if(t[rt].a)t[rt<<1].a=t[rt<<1|1].a=1;
	if(t[rt].b)t[rt<<1].b=t[rt<<1|1].b=1;
	pushdown(rt<<1);
	pushdown(rt<<1|1);
}
void upRange(int x,int y,int op)
{
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],op);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],op);
}
void dfs1(int x,int fa)
{
	dep[x]=dep[fa]+1;
	f[x]=fa;
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
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==son[x]||y==f[x])continue;
		dfs2(y,y);
	}	
}
void getpath(int x,int fa,int t,int dep=0)
{
	if(dep>maxdep){
		maxdep=dep;
		rt.clear();
		rt.push_back(x);
	}
	else if(dep==maxdep)
		rt.push_back(x);
	for(auto y:v[x])
	{
		if(y==t||y==fa)continue;
		getpath(y,x,t,dep+1);
	}
}
void mark(int top,int op)
{
	for(auto x:rt)
		upRange(top,x,op);
}
void solve()
{
	cin>>n>>S>>T;
	init();
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

	maxdep=0;
	getpath(S,0,T);
	mark(S,1);

	maxdep=0;
	getpath(T,0,S);
	mark(T,2);

	pushdown(1);


	vis[S]=vis[T]=1;
	while(1)
	{
		int ok;


		ok=0;
		for(auto y:v[S])
			if(!vis[y]&&a[y]){
				S=y;
				ok=1;
				break;
			}
		if(ok==0)
		{
			for(auto y:v[S])
				if(!vis[y]){
					S=y;
					ok=1;
					break;
				}
		}
		if(!ok){cout<<0<<endl;return ;}
		vis[S]=1;

		ok=0;
		for(auto y:v[T])
			if(!vis[y]&&b[y]){
				T=y;
				ok=1;
				break;
			}
		if(ok==0)
		{
			for(auto y:v[T])
				if(!vis[y]){
					S=y;
					ok=1;
					break;
				}
		}
		if(!ok){cout<<1<<endl;return ;}
		vis[T]=1;
	}
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}