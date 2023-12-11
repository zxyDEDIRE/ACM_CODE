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
struct Edge{int to,next;}edge[maxn];
struct Seg{	int l,r;}t[maxn<<2];
struct node{ll x,r;int id;}p[maxn];
vector<int>v[maxn<<1];
int head[maxn<<1],cnt;
int dfn[maxn<<1],low[maxn<<1];
int col[maxn<<1],num[maxn<<1];
bool vis[maxn<<1];
stack<int>s;
ll ans[maxn<<1];
ll a[maxn];
int in[maxn<<1];
int indx;
int n,tot,ma;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void build(int rt,int l,int r)
{
	t[rt]={l,r};
	if(l==r){
		ma=max(ma,n+rt);
		add(n+rt,l);
		return ;
	}
	add(n+rt,n+rt<<1);
	add(n+rt,n+rt<<1|1);
	int mid=(l+r)>>1;
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void S_add(int rt,int l,int r,int k)
{
	if(l<=t[rt].l&&t[rt].r<=r){
		add(n+rt,k);
		return ;
	}
	int mid=(t[rt].l+t[rt].r)>>1;
	if(l<=mid)S_add(rt<<1,l,r,k);
	if(r>mid)S_add(rt<<1|1,l,r,k);
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		do{
			y=s.top();
			if(y<=n)num[tot]++;
			s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

void solve()
{
	cin>>n;
	build(1,1,n);
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].r,p[i].id=i;
	sort(p+1,p+1+n,[&](node a,node b){
		return a.x<b.x;
	});
	for(int i=1;i<=n;i++)
		a[i]=p[i].x;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		auto [x,r,id]=p[i];
		int fa=lower_bound(a+1,a+1+n,x-r)-a;
		int fb=upper_bound(a+1,a+1+n,x+r)-a-1;
		if(fa<0)fa=1;if(fa>n)fa=n;
		if(fb<0)fb=1;if(fb>n)fb=n;
		S_add(1,fa,fb,i);
	}
	for(int i=1;i<=ma;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=ma;x++)
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(col[x]!=col[y])
				v[col[y]].push_back(col[x]);
		}
	for(int x=1;x<=tot;x++)
	{
		sort(v[x].begin(),v[x].end());
		v[x].erase(unique(v[x].begin(),v[x].end()),v[x].end());
		for(auto y:v[x])
			in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(!in[i])
			ans[i]=num[i],q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();==
		cout<<x<<endl;
		for(auto y:v[x])
		{
			in[y]--;
			ans[y]+=ans[x];
			if(!in[y])
				q.push(y);
		}
	}
	ll res=0;
	for(int i=1;i<=tot;i++)
		cout<<ans[i]<<" ";cout<<endl;
	for(int i=1;i<=n;i++)
	{
		res+=mull(ans[col[i]],p[i].id);
	}
	for(int i=1;i<=n;i++)
		cout<<col[i]<<" ";cout<<endl;
	cout<<res<<endl;

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