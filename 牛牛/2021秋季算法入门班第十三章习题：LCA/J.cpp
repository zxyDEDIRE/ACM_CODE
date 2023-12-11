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
const int maxn=1e6;
struct node{
	int x,y,w;
}a[maxn];
struct Seg{
	int l,r,val;
}t[maxn<<2];
vector<int>v[maxn];
int son[maxn],siz[maxn],fa[maxn],dep[maxn];
int id[maxn],di[maxn],top[maxn],tot;
int w[maxn];
int p[maxn];
int n,m,cnt;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void add(int x,int y,int ww)
{
	int to=++cnt;
	v[x].push_back(to);
	v[y].push_back(to);
	v[to].push_back(x);
	v[to].push_back(y);
	w[to]=ww;
}
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
	t[rt].val=min(t[rt<<1].val,t[rt<<1|1].val);
}
void build(int rt,int l,int r)
{
	t[rt].l=l;
	t[rt].r=r;
	if(l==r){
		t[rt].val=w[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query(int rt,int l,int r)
{
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val;
	int ans=INF;
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)ans=min(ans,query(rt<<1,l,r));
	if(r>mid)ans=min(ans,query(rt<<1|1,l,r));
	return ans;
}
int qRange(int x,int y)
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
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[i]={x,y,w};
	}
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w>b.w;
	});
	for(int i=1;i<=n;i++)
		p[i]=i,w[i]=INF;
	cnt=n;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=a[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			p[fa]=fb;
			add(x,y,w);
		}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(!dep[i])
		{
			dfs1(i,i,1);
			dfs2(i,i);
		}
	}
	build(1,1,cnt);
	int q;
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)cout<<-1<<endl;
		else cout<<qRange(x,y)<<endl;
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
5 7
4 3 4440
3 1 22348
1 3 28368
2 4 25086
5 3 6991
4 3 10638
3 1 11106
4
4 5
1 3
5 4
2 5

6991
28368
6991
6991

*/
