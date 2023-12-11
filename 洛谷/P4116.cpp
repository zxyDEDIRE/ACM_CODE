/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Seg{
	int l,r,val,c;
}t[maxn<<2];
int fa[maxn],dep[maxn],siz[maxn],son[maxn];
int top[maxn],id[maxn],di[maxn],tot;
vector<int>v[maxn];
int n,q;
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	t[rt].val=INF;
	if(l==r){
		t[rt].c=di[l];
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void pushup(int rt)
{
	// if(t[rt<<1].val<=t[rt<<1|1].val)
	// {
	// 	t[rt].val=t[rt<<1].val;
	// 	t[rt].c=t[rt<<1].c;
	// }
	// else if(t[rt<<1].val>t[rt<<1|1].val)
	// {
	// 	t[rt].val=t[rt<<1|1].val;
	// 	t[rt].c=t[rt<<1|1].c;
	// }
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void update(int rt,int l)
{
	if(t[rt].l==t[rt].r)
	{
		if(t[rt].val==INF)t[rt].val=l;
		else t[rt].val=INF;
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)update(rt<<1,l);
	else update(rt<<1|1,l);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		return t[rt].val;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
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

		// cout<<x<<" "<<y<<endl;
		// cout<<id[top[x]]<<" "<<id[x]<<endl;
		// cout<<ans<<endl;
		// cout<<"**********"<<endl;


		
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=min(ans,query(1,id[x],id[y]));
	return ans;
}
void dfs1(int x,int faa,int deep)
{
	fa[x]=faa;
	dep[x]=deep;
	siz[x]=1;
	int maxson=-1;
	for(auto y:v[x])
	{
		if(y==faa)continue;
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
	id[x]=++tot;
	di[tot]=x;
	top[x]=topf;
	if(son[x])dfs2(son[x],topf);
	for(auto y:v[x])
	{
		if(y==son[x]||y==fa[x])continue;
		dfs2(y,y);
	}
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

	while(q--)
	{
		int op,x;
		cin>>op>>x;
		if(op==0)update(1,id[x]);
		else
		{
			int t=qR(1,x);
			if(t==INF)cout<<-1<<endl;
			else cout<<t<<endl;
		}
	}

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*

9 3
1 2
1 3
2 4
2 9
5 9
7 9
8 9
6 8

1 3
0 3
1 3

*/