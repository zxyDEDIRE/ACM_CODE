/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
struct node{
	int l,r,val_1,val_2;
}t[maxn<<2];

vector<int>G[maxn];
vector<int>v[maxn];
int dfn[maxn],low[maxn],dfc,tot;
int stk[maxn],tp;
int _siz[maxn];
int siz[maxn];
int cut[maxn];

int id[maxn],di[maxn],top[maxn],id_cnt;
int fa[maxn],dep[maxn],son[maxn];
int si[maxn];

int n,m,root=1;
bool cmp(int a,int b){return a>b;}
void init()
{
	for(int i=1;i<=n*2;i++)
	{
		G[i].clear();
		v[i].clear();
		dfn[i]=0;
		cut[i]=0;
	}
	root=1;
	tp=0;
	id_cnt=0;
}
void tarjan(int x)
{
	dfn[x]=low[x]=++dfc;
	stk[++tp]=x;
	_siz[x]=1;
	int num=0;
	for(auto y:G[x])
	{
		if(!dfn[y])
		{
			num++;
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if(low[y]==dfn[x])
			{
				cut[x]=1;
				++tot;
				for(int u=0;u!=y;--tp){
					u=stk[tp];
					// cout<<tot<<" "<<u<<endl;
					v[tot].push_back(u);
					v[u].push_back(tot);
				}
				// cout<<tot<<" "<<x<<endl;
				v[tot].push_back(x);
				v[x].push_back(tot);
			}
		}
		else low[x]=min(low[x],dfn[y]);
	}
	if(x==root&&num==1)cut[x]=0;
}
void dfs1(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x]=f;
	si[x]=1;
	siz[x]=_siz[x];
	son[x]=0;
	int maxson=0;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		si[x]+=si[y];
		if(si[y]>maxson){
			maxson=si[y];
			son[x]=y;
		}
	}
}
void dfs2(int x,int topf)
{
	id[x]=++id_cnt;
	di[id_cnt]=x;
	top[x]=topf;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x]){
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}


void pushup(int rt)
{
	int p[4]={0,0,0,0};
	p[0]=t[rt<<1].val_1;
	p[1]=t[rt<<1].val_2;
	p[2]=t[rt<<1|1].val_1;
	p[3]=t[rt<<1|1].val_2;
	sort(p,p+4,cmp);
	t[rt].val_1=p[0];
	t[rt].val_2=p[1];
	// cout<<p[0]<<" "<<p[1]<<" "<<p[2]<<" "<<p[3]<<endl;
	// cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val_1<<" "<<t[rt].val_2<<endl;
	// cout<<endl;
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0,0};
	if(l==r){
		t[rt].val_1=siz[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
array<int,2> query(int rt,int l,int r)
{
	// cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val_1<<" "<<t[rt].val_2<<endl;
	if(l<=t[rt].l&&t[rt].r<=r)
		return {t[rt].val_1,t[rt].val_2};
	int mid=(t[rt].l+t[rt].r)>>1;
	array<int,4>p{0,0,0,0};
	if(l<=mid){
		auto x=query(rt<<1,l,r);
		p[0]=x[0];
		p[1]=x[1];
	}
	if(r>mid){
		auto x=query(rt<<1|1,l,r);
		p[2]=x[0];
		p[3]=x[1];
	}
	sort(p.begin(),p.end(),cmp);
	return {p[0],p[1]};
}
array<int,2> qRange(int x,int y)
{
	int ma=0,mb=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		auto now=query(1,id[top[x]],id[x]);
		mb=max(mb,now[0]);if(mb>ma)swap(ma,mb);
		mb=max(mb,now[1]);if(mb>ma)swap(ma,mb);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	auto now=query(1,id[x],id[y]);
	mb=max(mb,now[0]);if(mb>ma)swap(ma,mb);
	mb=max(mb,now[1]);if(mb>ma)swap(ma,mb);
	return {x,mb};
}


void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	tot=n;
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	while(cut[root])root++;
	dfs1(root,0);
	dfs2(root,root);
	build(1,1,tot);
	int q=0;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(!cut[x]&&!cut[y])cout<<n<<endl;
		else if(cut[x]&&cut[y])
		{
			if(dep[x]>dep[y])swap(x,y);
			auto now=qRange(x,y);
			if(now[0]==x)cout<<now[1]-siz[y]+2<<endl;
			else cout<<n-siz[x]-siz[y]+2<<endl;
		}
		else
		{
			if(cut[y])swap(x,y);
			auto now=qRange(x,y);
			if(now[0]==x)cout<<now[1]+1<<endl;
			else cout<<n-siz[x]+1<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}