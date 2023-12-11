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
const int mod=1e9;
struct node{
	int x,y,z;
};
node operator + (const node &a,const node &b)
{
	return {a.x+b.x,a.y+b.y,a.z+b.z};
}
struct Seg{
	int l,r;
	node val;
}t[maxn<<2];
int fa[maxn],siz[maxn],dep[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],tot;
vector<int>v[maxn];
node init={0,0,0};
int n,q;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=init;
	if(l==r)
	{
		int x=di[l];
		while(x%10==0)t[rt].val.x++,x/=10;t[rt].val.x*=siz[di[l]];
		while(x%5==0)t[rt].val.y++,x/=5;t[rt].val.y*=siz[di[l]];
		while(x%2==0)t[rt].val.z++,x/=2;t[rt].val.z*=siz[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
node query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	node ans=init;
	if(l<=mid)ans=ans+query(rt<<1,l,r);
	if(r>mid)ans=ans+query(rt<<1|1,l,r);
	return ans;
}
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
void LCA(int x,int y)
{
	node ans=init;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans=ans+query(1,id[top[x]],id[x]);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=ans+query(1,id[x],id[y]);
	int a=ans.x;
	int b=ans.y;
	int c=ans.z;
	cout<<a<<" "<<b<<" "<<c<<endl;
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

	for(int i=1;i<=n;i++)
		cout<<id[i]<<" ";
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		node ans=query(1,i,i);
		cout<<ans.x<<" "<<ans.y<<" "<<ans.z<<endl;
	}
	cout<<endl;
	// while(q--)
	// {
	// 	int x;
	// 	cin>>x;
	// 	LCA(1,x);
	// }
	LCA(1,3);


	
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}