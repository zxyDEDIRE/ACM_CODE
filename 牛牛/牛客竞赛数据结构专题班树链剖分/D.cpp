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
	int l,r,val,lazy;
}t[maxn<<2];
vector<int>v[maxn];
int fa[maxn],dep[maxn],son[maxn],siz[maxn];
int id[maxn],di[maxn],top[maxn],tot;
int n,q;
void dfs1(int x,int f,int deep)
{
	fa[x]=f;
	siz[x]=1;
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
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r)return ;
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy==1)
	{
		t[rt<<1].val=(t[rt<<1].r-t[rt<<1].l+1);
		t[rt<<1|1].val=(t[rt<<1|1].r-t[rt<<1|1].l+1);
		t[rt<<1].lazy=t[rt].lazy;
		t[rt<<1|1].lazy=t[rt].lazy;
		t[rt].lazy=0;
	}
	else if(t[rt].lazy==-1)
	{
		t[rt<<1].val=t[rt<<1|1].val=0;
		t[rt<<1].lazy=t[rt].lazy;
		t[rt<<1|1].lazy=t[rt].lazy;
		t[rt].lazy=0;
	}
}
int query(int rt,int l,int r)
{
	// cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r);
	if(r>mid)ans+=query(rt<<1|1,l,r);
	return ans;
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy=k;
		if(k==1)t[rt].val=(t[rt].r-t[rt].l+1);
		else t[rt].val=0;
		return ;
	}
	pushdown(rt);
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l,r,k);
	if(r>mid)update(rt<<1|1,l,r,k);
	pushup(rt);
}
int qR(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans+=query(1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans+=query(1,id[x],id[y]);
	return ans;
}
int qS(int x)
{
	return query(1,id[x],id[x]+siz[x]-1);
}
void uQ(int x,int y,int k)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		// cout<<id[top[x]]<<" "<<id[x]<<endl;
		update(1,id[top[x]],id[x],k);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	// cout<<id[x]<<" "<<id[y]<<endl;
	update(1,id[x],id[y],k);
}
void uS(int x)
{
	update(1,id[x],id[x]+siz[x]-1,-1);
}
void dfs(int rt)
{
	cout<<t[rt].l<<" "<<t[rt].r<<" "<<t[rt].val<<endl;
	pushdown(rt);
	if(t[rt].l==t[rt].r)return ;
	dfs(rt<<1);
	dfs(rt<<1|1);
}
void solve()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int x;cin>>x;
		v[x+1].push_back(i);
	}
	dfs1(1,1,1);
	dfs2(1,1);
	build(1,1,n);
	// for(int i=1;i<=n;i++)
	// 	cout<<id[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<dep[i]<<" ";cout<<endl;
	cin>>q;
	while(q--)
	{
		string str;
		int x;
		// cout<<"**************"<<endl;
		cin>>str>>x;
		x++;
		if(str=="install")
		{
			int ans_1=qR(1,x);
			cout<<dep[x]-ans_1<<endl;
			// cout<<dep[x]<<" "<<ans_1<<endl;
			uQ(1,x,1);
		}
		else
		{
			int ans_1=qS(x);
			cout<<ans_1<<endl;
			uS(x);
		}
		// cout<<"**************"<<endl;
		// dfs(1);
	}
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
7
0 0 0 1 1 5
3
install 5
install 6
uninstall 1
install 4
uninstall 0
*/