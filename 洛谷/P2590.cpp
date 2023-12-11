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
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Seg{
	int l,r,val,max;
}t[maxn<<2];
vector<int>v[maxn];
int dep[maxn],fa[maxn],siz[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],tot;
int w[maxn];
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
		if(y==son[x]||y==fa[x])continue;
		dfs2(y,y);
	}
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
	t[rt].max=max(t[rt<<1].max,t[rt<<1|1].max);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=t[rt].max=w[di[l]];
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
		t[rt].val=t[rt].max=k;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,k);
	else update(rt<<1|1,l,k);
	pushup(rt);
}
int query(int rt,int l,int r,int op)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		if(op==1)return t[rt].val;
		else return t[rt].max;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans;
	if(op==1)
	{
		ans=0;
		if(l<=mid)ans+=query(rt<<1,l,r,op);
		if(r>mid)ans+=query(rt<<1|1,l,r,op);
	}
	else
	{
		ans=-INF;
		if(l<=mid)ans=max(ans,query(rt<<1,l,r,op));
		if(r>mid)ans=max(ans,query(rt<<1|1,l,r,op));
	}
	return ans;
}
int qRange(int x,int y,int op)
{
	int ans=0;
	if(op==1)ans=0;
	else ans=-INF;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		if(op==1)ans+=query(1,id[top[x]],id[x],op);
		else ans=max(ans,query(1,id[top[x]],id[x],op));
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(op==1)ans+=query(1,id[x],id[y],op);
	else ans=max(ans,query(1,id[x],id[y],op));
	return ans;
}
void dfs(int rt)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<" "<<t[rt].max<<endl;
	if(t[rt].l==t[rt].r)return ;
	dfs(rt<<1);
	dfs(rt<<1|1);
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
	for(int i=1;i<=n;i++)
		cin>>w[i];
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);
	cin>>q;
	while(q--)
	{
		string op;
		cin>>op;
		if(op=="CHANGE")
		{
			int x,y;
			cin>>x>>y;
			update(1,id[x],y);
		}
		else if(op=="QMAX")
		{
			int x,y;
			cin>>x>>y;
			cout<<qRange(x,y,2)<<endl;
		}
		else if(op=="QSUM")
		{
			int x,y;
			cin>>x>>y;
			cout<<qRange(x,y,1)<<endl;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
4
1 2
2 3
4 1
4 2 1 3
1
QSUM 3 4


7
1 2
1 3
2 4
2 5
3 6
3 7
1 2 3 4 5 6 7
10
*/