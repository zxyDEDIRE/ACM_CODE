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
const int maxn=5e6+100;
struct EDGE{
	int to,next,w;
}edge[maxn];
struct node{
	int x,y,w;
}a[maxn];
int head[maxn],cnt;
int siz[maxn],son[maxn],dep[maxn],fa[maxn];
int top[maxn];
int f[maxn];
int l1,l2,r1,r2;
int n,m;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void kruskal()
{
	sort(a+1,a+1+m,[&](node a,node b){
		return a.w<b.w;
	});
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,w]=a[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			add(x,y,w);
			add(y,x,w);
			f[fa]=fb;
		}
	}
}
void dfs(int x,int fa,int d,int& r,int& l)
{
	if(d>l){
		l=d;
		r=x;
	}
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa)continue;
		dfs(y,x,d+edge[i].w,r,l);
	}
}
void dfs1(int x,int f,int deep)
{
	dep[x]=deep;
	siz[x]=1;
	fa[x]=f;
	int maxson=-1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==f)continue;
		dfs1(y,x,deep+edge[i].w);
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
	if(son[x])dfs2(son[x],topf);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(y==fa[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
int LCA(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
int dis(int x,int y)
{
	int r=LCA(x,y);
	return dep[x]+dep[y]-dep[r]*2;
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
	kruskal();
	dfs(1,0,0,r1,l1);
	dfs(r1,0,0,r2,l2);
	dfs1(1,0,1);
	dfs2(1,1);
	int t=dis(r1,r2);
	int ma=t;
	for(int i=1;i<=n;i++)
		ma=max(ma,t+min(dis(r1,i),dis(r2,i)));
	cout<<ma<<endl;
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