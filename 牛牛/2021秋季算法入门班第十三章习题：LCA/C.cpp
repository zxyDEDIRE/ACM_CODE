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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const ull str_mod=212370440130137957ll;
const ull more=19260817;
const ull prime=233317;
const ull base=131;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+10;
struct node{
	int l,r,val;
}t[maxn<<2];
vector<int>v[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int p[maxn];
int n,m,s;
void dfs1(int x,int f,int deep)
{
	siz[x]=1;
	dep[x]=deep;
	fa[x]=f;
	int maxson=-1;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)
		{
			maxson=siz[x];
			son[x]=y;
		}
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
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		t[rt].val=p[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int k)
{
	if(t[rt].l==t[rt].r)
	{
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
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
int qSon(int x)
{
	return query(1,id[x],id[x]+siz[x]-1);
}
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(s,0,1);
	dfs2(s,s);
	build(1,1,n);
	while(m--)
	{
		int op;cin>>op;
		if(op==1)
		{
			int x,k;
			cin>>x>>k;
			update(1,id[x],k);
		}
		else
		{
			int x;
			cin>>x;
			cout<<qSon(x)<<endl;
		}
	}
}
signed main(){
//	freopen("C:\\Users\\19254\\Desktop\\P4011_2.in.txt","r",stdin);
//	freopen("C:\\Users\\19254\\Desktop\\P4011_2.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//	fclose(stdin);
//	fclose(stdout);
	return 0;
}