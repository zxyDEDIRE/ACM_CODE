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
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=2e5+100;
struct node{
	int l,r,val_1,val_2;
}t[maxn<<2];
int fa[maxn],siz[maxn],dep[maxn],son[maxn];
int id[maxn],di[maxn],top[maxn],tot;
vector<pii>v[maxn];
int f[maxn][20];
int a[maxn];
int p[maxn];
int w[maxn];
int n,k;
void build(int rt,int l,int r)
{
	t[rt]={l,r,0ll,0ll};
	if(l==r){
		t[rt]={l,r,a[di[l]],w[di[l]]};
		return ;
	}
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
	t[rt].val_1=t[rt<<1].val_1+t[rt<<1|1].val_1;
	t[rt].val_2=t[rt<<1].val_2+t[rt<<1|1].val_2;
}
int query(int rt,int l,int r,int fl)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		if(fl==0)return t[rt].val_1;
		return t[rt].val_2;
	}
	int mid=(t[rt].l+t[rt].r)/2;
	int ans=0;
	if(l<=mid)ans+=query(rt<<1,l,r,fl);
	if(r>mid)ans+=query(rt<<1|1,l,r,fl);
	return ans;
}
int qRange(int x,int y,int fl)
{
	int ans=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		ans+=query(1,id[top[x]],id[x],fl);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	if(fl==0)
		ans+=query(1,id[x],id[y],fl);
	if(fl==1&&id[x]!=id[y])
		ans+=query(1,id[x]+1,id[y],fl);
	return ans;
}
void dfs1(int x,int pa,int deep)
{
	siz[x]=1;
	fa[x]=f[x][0]=pa;
	dep[x]=deep;
	int maxson=-1;
	for(int i=1;i<20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto [y,W]:v[x])
	{
		if(y==pa)continue;
		w[y]=W;
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
	for(auto [y,w]:v[x])
		if(y!=fa[x]&&y!=son[x])
			dfs2(y,y);
}
void init()
{
	for(int i=1;i<=n;i++)
	{
		son[i]=0;
		v[i].clear();
		for(int j=0;j<20;j++)
			f[i][j]=0;
	}
	tot=0;
}
void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		cin>>p[i];
	for(int i=2,x;i<=n;i++){
		cin>>x;
		v[p[i]].push_back({i,x});
	}
	dfs1(1,0,0);
	dfs2(1,1);
	build(1,1,n);
	int mi=LLONG_MAX;
	for(int x=1;x<=n;x++)
	{
		int now=x;
		int i=19;
		while(i>=0)
		{
			if(f[now][i]!=0)
			{
				if(qRange(f[now][i],x,0)<=k)
					now=f[now][i];
			}
			i--;
		}
		int cos=qRange(now,x,0);
		while(1)
		{
			if(!fa[now])break;
			if(cos<k)
			{
				now=fa[now];
				cos=qRange(now,x,0);
			}
			else break;
		}
		if(cos>=k)
			mi=min(mi,qRange(now,x,1));
	}
	if(mi==LLONG_MAX)cout<<-1<<endl;
	else cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
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
4 11
2 5 6 10
1 2 1
20 1 2
8 11
2 6 3 7 8 4 9 10
1 1 2 2 3 6 6
2 20 10 10 2 3 5
*/