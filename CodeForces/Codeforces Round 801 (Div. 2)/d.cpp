#include<bits/stdc++.h>
#define mid ((t[rt].l+t[rt].r)>>1)
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
int to[maxn<<1],nex[maxn<<1],head[maxn<<1],cnt;
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int id[maxn],wt[maxn],top[maxn];
int w[maxn];
int tot;
int n,m,r,p=1e9;
int res;
struct Seg{
	int l,r,val,lazy;
}t[maxn<<2];
inline void add(int from,int too)
{
	to[++cnt]=too;
	nex[cnt]=head[from];
	head[from]=cnt;
}

inline void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
inline void pushdown(int rt)
{
	t[rt<<1].lazy+=t[rt].lazy;
	t[rt<<1|1].lazy+=t[rt].lazy;

	t[rt<<1].val+=t[rt].lazy*(t[rt<<1].r-t[rt<<1].l+1);
	t[rt<<1|1].val+=t[rt].lazy*(t[rt<<1|1].r-t[rt<<1|1].l+1);



	t[rt].lazy=0;
}
inline void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)
	{
		t[rt].val=1;
		return ;
	}
	int md=(l+r)>>1;
	build(rt<<1,l,md);
	build(rt<<1|1,md+1,r);
	pushup(rt);
}
inline void query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		res+=t[rt].val;
		return ;
	}
	if(t[rt].lazy) pushdown(rt);
	if(l<=mid)query(rt<<1,l,r);
	if(r>mid)query(rt<<1|1,l,r);
	pushup(rt);
}
inline int f(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		res=0;
		query(1,id[top[x]],id[x]);
		ans+=res;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	res=0;
	query(1,id[x],id[y]);
	ans+=res;
	return ans;
}
inline void dfs1(int x,int f,int deep)//当前点，父亲点，深度
{
	dep[x]=deep;	//记录每个点的深度
	fa[x]=f;	//记录每个点的父亲
	siz[x]=1;	//记录每个点子树大小
	int maxson=-1;	//记录重儿子的儿子树 要计较
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==f)continue;
		dfs1(y,x,deep+1);	//遍历儿子
		siz[x]+=siz[y];	//加上子树大小
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];//记录比较重儿子
	}
}
inline void dfs2(int x,int topf)//当前节点，topf当前链的链首
{
	id[x]=++tot;	//标记每个点的新编号
	top[x]=topf;	//当前点的链首
	if(!son[x])return ;	//没有儿子
	dfs2(son[x],topf);	//先处理重儿子，在处理轻儿子
	for(int i=head[x];i;i=nex[i])
	{
		int y=to[i];
		if(y==fa[x]||y==son[x])
			continue;

		dfs2(y,y);//新建重链
	}

}
void init()
{
	cnt=0;tot=0;
	for(int i=1;i<=n;i++){
		head[i]=0,son[i]=0;
	}
		
}
void solve()
{
	cin>>n;
	init();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	if(n==1){
		cout<<0<<endl;
		return ;
	}
	dfs1(1,1,0);
	dfs2(1,1);
	build(1,1,n);
	int ans=1;
	for(int i=1;i<=n;i++)
	{
		map<int,int>mp;
		int ma=0;
		for(int j=1;j<=n;j++)
		{
			//if(i==j)continue;
			int ss=f(i,j);
			int tt=++mp[ss];
			if(tt>1)ma++;
		}
		ans=max(ans,ma);
	}
	cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
    solve();
    return 0;
}