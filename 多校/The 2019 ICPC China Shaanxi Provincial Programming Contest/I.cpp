/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
	int l,r,val,lazy;
}t[maxn<<2];
int dep[maxn],f[maxn],siz[maxn],son[maxn],top[maxn],id[maxn],di[maxn],indx;
vector<pair<int,char>>v[maxn];
int p[maxn];
int n,ans;
void pushup(int rt)
{
	t[rt].val=t[rt<<1].val+t[rt<<1|1].val;
}
void pushdown(int rt)
{
	if(t[rt].lazy)
	{
		int m=(t[rt].l+t[rt].r)>>1;
		t[rt<<1].lazy+=t[rt].lazy;
		t[rt<<1|1].lazy+=t[rt].lazy;

		t[rt<<1].val+=(m-t[rt].l+1)*t[rt].lazy;
		t[rt<<1|1].val+=(t[rt].r-m)*t[rt].lazy;

		t[rt].lazy=0;
	}
}
void build(int rt,int l,int r)
{
	t[rt]={l,r,0};
	if(l==r)return ;
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void update(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r)
	{
		t[rt].lazy+=k;
		t[rt].val+=(t[rt].r-t[rt].l+1)*k;
		return ;
	}
	pushdown(rt);
	int m=(t[rt].l+t[rt].r)>>1;
	if(l<=m)	update(rt<<1,l,r,k);
	if(r>m)	update(rt<<1|1,l,r,k);
	pushup(rt);
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
	}
	indx=0;
	ans=1;
}
void dfs1(int x,int fa)
{
	f[x]=fa;
	dep[x]=dep[fa]+1;
	siz[x]=1;
	son[x]=0;
	for(auto [y,c]:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		siz[x]+=siz[y];
		if(siz[y]>siz[son[x]])
			son[x]=y;
	}
}
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++indx;
	di[indx]=x;
	if(son[x])dfs2(son[x],topf);
	for(auto [y,c]:v[x])
	{
		if(y==f[x]||y==son[x])continue;
		dfs2(y,y);
	}
}
inline void upRange(int x,int y,int k)
{
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		update(1,id[top[x]],id[x],k);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	update(1,id[x],id[y],k);
}
inline void upSon(int x,int k){
	// cout<<"upson "<<x<<" "<<k<<endl;
	update(1,id[x],id[x]+siz[x]-1,k);
}

void dfs3(int x)
{
	if(ans==0)return ;
	map<char,int>mp;
	for(auto [y,c]:v[x])
		mp[c]++;
	char now='?';
	for(auto [x,y]:mp)
	{
		if(y>2)ans=0;
		if(y==2)
		{
			if(now!='?')ans=0;
			else now=x;
		}
	}
	if(now!='?'&&ans)
	for(auto [y,c]:v[x])
	{
		if(c==now)continue;
		if(y==f[x])
		{
			upSon(1,-1);
			upSon(x,1);
		}
		else
		{
			upSon(y,-1);
		}
	}
	if(now!='?')
		update(1,id[x],id[x],-1);
	for(auto [y,c]:v[x])
	{
		if(y==f[x])continue;
		dfs3(y);
	}
}
void dfs4(int rt)
{
	if(t[rt].l==t[rt].r){
		p[t[rt].l]=t[rt].val;
		return ;
	}
	pushdown(rt);
	dfs4(rt<<1);
	dfs4(rt<<1|1);
}
void solve()
{
	cin>>n;
	init();
	for(int i=1;i<n;i++)
	{
		int x,y;char c;
		cin>>x>>y>>c;
		v[x].push_back({y,c});
		v[y].push_back({x,c});
	}
	dfs1(1,0);
	dfs2(1,1);
	build(1,1,n);
	dfs3(1);
	if(ans==0){
		cout<<0<<endl;
		return ;
	}
	dfs4(1);
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,p[i]);
	// for(int i=1;i<=n;i++)
	// 	cout<<"i:"<<i<<" p:"<<p[i]<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<"i:"<<i<<" id:"<<id[i]<<endl;
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(p[i]==ma)
			cnt++;
	cout<<cnt<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
7
1 2 a
1 3 a
2 4 b
2 5 b
3 6 b
3 7 b
*/