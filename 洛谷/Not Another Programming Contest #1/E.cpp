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
bitset<maxn>vis,is;
int myTOT=0;
int n,q,k;
void pushup(int rt)
{
	t[rt].val1=max(t[rt<<1].val1,t[rt<<1|1].val1);
	t[rt].val2=t[rt<<1].val2+t[rt<<1|1].val2;
}
void build(int rt,int l,int r){
	t[rt]={l,r,0,0};
	if(l==r){
		if(is[di[l]])t[rt].val1=l;
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
	int ans=0;
	if(l<=mid)ans=max(ans,query1(rt<<1,l,r));
	if(r>mid)ans=max(ans,query1(rt<<1|1,l,r));
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
	int ma=0;
	int sum=0;
	// cout<<x<<" "<<y<<endl;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y); 
		// cout<<"1 x y "<<x<<" "<<y<<endl;
		ma=max(ma,query1(1,id[top[x]],id[x]));
		sum+=query2(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ma=max(ma,query1(1,id[x],id[y]));
	sum+=query2(1,id[x],id[y]);
	// cout<<"lca "<<x<<endl;
	// cout<<"mi "<<mi<<endl;
	// cout<<"sum "<<sum<<endl;
	return ma+sum-c[x];
}
inline int find(int x,int y)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y); 
		ans=max(ans,query1(1,id[top[x]],id[x]));
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	ans=max(ans,query1(1,id[x],id[y]));
	return ans;
}
inline int have(int x)
{
	int ans=query1(1,id[x],id[x]+siz[x]-1);
	if(ans!=0)return 1;
	else return 0;
}
inline int LCA_dis(int x,int y)
{
	int sum=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y); 
		sum+=query2(1,id[top[x]],id[x]);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	sum+=query2(1,id[x],id[y]);
	return sum-c[x];
}
inline int LCA(int x,int y)
{
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
inline bool dfs(int x,int fa)
{
	int flag=0;
	for(auto [y,w]:v[x])
	{
		if(y==fa)continue;
		int now=dfs(y,x);
		if(now)myTOT+=w*2;
		flag|=now;
	}
	if(is[x])flag|=1;
	return flag;
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
		cin>>p[i],is[p[i]]=1;
	dfs1(1,0);
	dfs2(1,1);


	int myLCA=p[0];


	for(auto x:p)
		myLCA=LCA(myLCA,x);

	dfs(myLCA,0);
	build(1,1,n);

	auto f=[&](int x,int y)->int{
		int now = find(x,y);
		if(now==0)return LCA_dis(x,y);
		else
			return LCA_dis(x,di[now])-LCA_dis(di[now],y);
	};

	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<i<<" id "<<id[i]<<endl;
	// for(int i=1;i<=n;i++){
	// 	if(is[di[i]])cout<<i<<endl;
	// }
	// cout<<endl;

	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=0;
		ans=myTOT;
		// cout<<"have(x) "<<have(x)<<endl;
		// cout<<"have(y) "<<have(y)<<endl;

		int now_lca=LCA(x,y);


		if(LCA(now_lca,myLCA)!=myLCA)
			now_lca=myLCA;

		if(!have(now_lca))
		{
			int fi = find(now_lca,myLCA);
			// cout<<"fi "<<di[fi]<<" "<<fi<<endl;
			if(fi==0)ans+=LCA_dis(now_lca,myLCA)*2;
			else ans+=LCA_dis(now_lca,di[fi])*2;
		}

		// cout<<"now_lca "<<now_lca<<endl;
		// cout<<"myLCA "<<myLCA<<endl;
		// cout<<ans<<endl;
		if(have(x))ans=ans-LCA_dis(x,now_lca);
		else ans=ans+f(x,now_lca);
		// cout<<ans<<endl;
		if(have(y))ans=ans-LCA_dis(y,now_lca);
		else ans=ans+f(y,now_lca);

		cout<<ans<<endl;
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
1 6


2 3
2 1
7 1
4 5
6 6
*/