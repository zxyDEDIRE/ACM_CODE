/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Seg{
	int l,r,val,same,lazy;
}t[maxn<<2];
vector<int>v[maxn];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int n,q;
void dfs1(int x,int f,int deep)
{
	siz[x]=1;
	fa[x]=f;
	dep[x]=deep;
	int maxson=-1;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		if(siz[y]>maxson)
		{
			maxson=siz[y];
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
	if(t[rt<<1].same==1&&t[rt<<1|1].same==1&&t[rt<<1].val==t[rt<<1|1].val)
		t[rt].same=1,t[rt].val=t[rt<<1].val;
	else t[rt].same=0;
}
void pushdown(int rt)
{
	if(t[rt].lazy%2)
	{
		t[rt<<1].val^=1;
		t[rt<<1|1].val^=1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;
		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
void update(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=1;
		t[rt].lazy%=2;
		if(t[rt].same)t[rt].val^=1;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r);
	if(r>mid)update(rt<<1|1,l,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(t[rt].val==0&&t[rt].same==1)return INF;
	if(l<=t[rt].l&&t[rt].r<=r&&t[rt].val==1&&t[rt].same==1)
		return t[rt].l;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r);
	int ans=INF;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
int qR(int x,int y)
{
	int ans=INF;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=min(ans,query(1,id[top[x]],id[x]));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=min(ans,query(1,id[x],id[y]));
	return ans;
}
void solve()
{
	cin>>n>>q;
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
	cout<<"Yes"<<endl;
	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==0)
		{
			update(1,id[x],id[x]);
		}
		else
		{
			int ans=qR(1,x);
			if(ans=INF)cout<<-1<<endl;
			else cout<<di[ans]<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}