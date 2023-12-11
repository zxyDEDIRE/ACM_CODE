/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Seg{
	int l,r,val1,val2;
}t[maxn<<2];
vector<pii>v[maxn];
vector<int>p;
int dep[maxn],siz[maxn],f[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],c[maxn],tot;
int dis[maxn];
bitset<maxn>vis;
int n,q,k;
void pushup(int rt)
{
	t[rt].val1=min(t[rt<<1].val1,t[rt<<1|1].val1);
	t[rt].val2=t[rt<<1].val2+t[rt<<1|1].val2;
}
void build(int rt,int l,int r){
	t[rt]={l,r,INF,0};
	if(l==r){
		t[rt].val1=dis[di[l]]*2;
		t[rt].val2=c[di[l]];
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	pushup(rt);
}
int query1(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r)
		return t[rt].val1; 
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=INF;
	if(l<=mid)ans=min(ans,query1(rt<<1,l,r));
	if(r>mid)ans=min(ans,query1(rt<<1|1,l,r));
	return ans;
}
int query2(int rt,int l,int r){
	if(l<=t[rt].l&&t[rt].r<=r){
		return t[rt].val2;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	int ans=0;
	if(l<=mid)ans+=query2(rt<<1,l,r);
	if(r>mid)ans+=query2(rt<<1|1,l,r);
	return ans;
}
void dfs1(int x,int fa){
	dep[x]=dep[fa]+1;
	siz[x]=1;
	f[x]=fa;
	son[x]=0;
	for(auto [y,w]:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		c[y]=w;
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int topf){
	top[x]=topf;
	id[x]=++tot;
	di[tot]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto [y,w]:v[x])
	{
		if(y==son[x]||y==f[x])continue;
		dfs2(y,y);
	}
}
int qRange(int x,int y)
{
	int mi=INF;
	int sum=0;
	// cout<<x<<" "<<y<<endl;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y); 
		// cout<<"1 x y "<<x<<" "<<y<<endl;
		mi=min(mi,query1(1,id[top[x]],id[x]));
		sum+=query2(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	mi=min(mi,query1(1,id[x],id[y]));
	sum+=query2(1,id[x],id[y]);
	// cout<<"lca "<<x<<endl;
	// cout<<"mi "<<mi<<endl;
	// cout<<"sum "<<sum<<endl;
	return mi+sum-c[x];
}
void solve()
{
	cin>>n>>q>>k;
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	p.resize(k);
	for(int i=0;i<k;i++)
		cin>>p[i];
	dfs1(1,0);
	dfs2(1,1);
	priority_queue<node>Q;
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	for(auto y:p)
		dis[y]=0,Q.push({y,0}); 
	while(!Q.empty())
	{
		auto [x,DIS]=Q.top();Q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(auto [y,w]:v[x])
			if(dis[y]>dis[x]+w){
				dis[y]=dis[x]+w;
				Q.push({y,dis[y]});
			}
	}
	build(1,1,n);

	while(q--)
	{
		int s,t;
		cin>>s>>t;
		cout<<qRange(s,t)<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
7 1 2
1 2 3
1 3 5
3 4 2
3 5 4
2 6 1
1 7 1
2 3
4 5


2 3
2 1
7 1
4 5
6 6
2 2
*/