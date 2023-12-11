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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Seg{
	int l,r,val,lazy,same;
}t[maxn<<2];
vector<int>v[maxn];
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],tot;
int n,q,ans,flag;
inline void dfs1(int x,int f,int deep)
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
		if(siz[y]>maxson)son[x]=y,maxson=siz[y];
	}
}
inline void dfs2(int x,int topf)
{
	id[x]=++tot;
	di[tot]=x;
	top[x]=topf;
	if(!son[x])return ;
	dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==fa[x]||y==son[x])
			continue;
		dfs2(y,y);
	}
}

void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=1;
	t[rt].same=1;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	if(t[rt<<1].val==t[rt<<1|1].val&&t[rt<<1].same==1&&t[rt<<1|1].same==1)t[rt].val=t[rt<<1].val,t[rt].same=1;
	else t[rt].same=0;
}
void pushdown(int rt)
{
	if(t[rt].lazy%2)
	{
		if(t[rt<<1].same)t[rt<<1].val^=1;
		if(t[rt<<1|1].same)t[rt<<1|1].val^=1;
		t[rt<<1].lazy=t[rt<<1|1].lazy=1;
		t[rt].lazy=0;
	}
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(t[rt].same==1)t[rt].val^=1;
		t[rt].lazy++;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(t[rt].same==1&&t[rt].val==0)return 2;
		else if(t[rt].same==0)return 3;
		else return 1;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int res=0;
	if(l<=mid)
	{
		int x=query(rt<<1,l,r);
		if(x!=0)res=x;
	}
	if(r>mid)
	{
		int x=query(rt<<1|1,l,r);
		if(res==0)res=x;
		else if(res!=x)res=3;
	}
	return res;
}
inline int qSon(int x)
{
	int res=query(1,id[x],id[x]+siz[x]-1);
	return res;
}
inline void upSon(int x)
{
	update(1,id[x],id[x]+siz[x]-1);
}

void dfs(int x)
{
	int a=qSon(x);
	int b=query(1,id[x],id[x]);
	//cout<<x<<" "<<a<<endl;
	if(a==1)return ;
	else if(a==2)
	{
		ans++;
		upSon(x);
	}
	else if(a==3)
	{
		if(b==2)
		{
			ans++;
			upSon(x);
		}
		for(auto y:v[x])
			dfs(y);
	}
}
void solve()
{
	cin>>n>>q;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x].push_back(i);
	}
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);
	while(q--)
	{
		int m;cin>>m;
		while(m--){
			int x;cin>>x;
			update(1,id[x],id[x]);
		}
		ans=0;
		dfs(1);
		cout<<ans<<endl;
	}
}
signed main(){
 // freopen("C:\Users\tob\Desktop\P4391_9.in.txt","r",stdin);
 // freopen("C:\Users\tob\Desktop\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}