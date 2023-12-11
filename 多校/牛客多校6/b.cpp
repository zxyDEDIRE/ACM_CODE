/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int id[maxn],p[maxn],top[maxn],di[maxn];
vector<int>v[maxn];
int w[maxn];
int tot;
int n,m,r;
int res;
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];
inline void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=0;
	if(l==r)return ;
	int md=(l+r)>>1;
	build(rt<<1,l,md);
	build(rt<<1|1,md+1,r);
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int m=(t[rt].l+t[rt].r)>>1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;

		t[rt<<1].val+=(m-t[rt].l+1)*t[rt].lazy;
		t[rt<<1|1].val+=(t[rt].r-m)*t[rt].lazy;

		t[rt].lazy=0;
	}
}
inline void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=k;
		t[rt].val+=(t[rt].r-t[rt].l+1)*k;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
}
inline void dfs1(int x,int f,int deep)//当前点，父亲点，深度
{
	dep[x]=deep;	//记录每个点的深度
	fa[x]=f;	//记录每个点的父亲
	siz[x]=1;	//记录每个点子树大小
	int maxson=-1;	//记录重儿子的儿子树 要计较
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x,deep+1);	//遍历儿子
		siz[x]+=siz[y];	//加上子树大小
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//记录比较重儿子
	}
}
inline void dfs2(int x,int topf)//当前节点，topf当前链的链首
{
	id[x]=++tot;	//标记每个点的新编号
	di[tot]=x;
	top[x]=topf;	//当前点的链首
	if(!son[x])return ;	//没有儿子
	dfs2(son[x],topf);	//先处理重儿子，在处理轻儿子
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])
			continue;

		dfs2(y,y);//新建重链
	}

}
void dfs(int rt)
{
	if(t[rt].l==t[rt].r){
		w[di[t[rt].l]]+=t[rt].val;
		return ;
	}
	pushdown(rt);
	dfs(rt<<1);
	dfs(rt<<1|1);
}
inline void upRange(int x,int t)
{
	int y;
	t++;
	int fl=0;
	while(t>0)
	{
		y=top[x];
		if(dep[x]-dep[y]+1<=t)
		{
			update(1,id[top[x]],id[x],1);
			if(id[top[x]]==1)fl=1;
			t-=dep[x]-dep[y]+1;
			x=fa[top[x]];
		}
		else
		{
			update(1,max(id[x]-t+1,1),id[x],1);
			if(id[x]-t+1==1)fl=1;
			t=0;
		}
		if(fl)break;
	}
}

void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		upRange(i,x);
	}
	dfs(1);
	for(int i=1;i<=n;i++)
		cout<<w[i]<<" ";
	cout<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
2
3 3
..A
B..
...
*/