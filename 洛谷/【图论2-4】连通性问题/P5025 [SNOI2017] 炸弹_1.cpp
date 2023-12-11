#include<bits/stdc++.h>
using namespace std;
using ll=long long;
#define int long long
const int maxn=2e6+1e6+6e5;
const int mod=1e9+7;
const int N=3e6;
struct Edge{int to,next;}edge[maxn];
struct node{int id;ll x,y;}p[N];
int low[maxn],dfn[maxn],indx;
vector<int>v[maxn];
int col[maxn],num;
int head[maxn],cnt;
bitset<maxn>vis;
int l[maxn];
int r[maxn];
stack<int>s;
ll a[maxn];
int in[maxn];
int n,tot;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void build(int rt,int l,int r)
{
	if(l==r)return ;
	tot=max(tot,n+rt);
	int mid=(l+r)>>1;
	if(l!=mid)add(n+rt,n+(rt<<1));
	else add(n+rt,l);
	if(mid+1!=r)add(n+rt,n+(rt<<1|1));
	else add(n+rt,r);
	build(rt<<1,l,mid);
	build(rt<<1|1,mid+1,r);
}
void query(int rt,int L,int R,int l,int r,int k)
{
	if(l<=L&&R<=r)
	{
		add(k,n+rt);
		return ;
	}
	int mid=(L+R)>>1;
	if(l<=mid)query(rt<<1,L,mid,l,r,k);
	if(r>mid)query(rt<<1|1,mid+1,R,l,r,k);
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
		num++;
		int y;
		do{
			y=s.top();s.pop();
			col[y]=num;vis[y]=0;
			if(y<=n)l[num]=min(l[num],y),r[num]=max(r[num],y);
		}while(x!=y);
	}
}
ll mull(ll a,ll b){ll qw=0;while(b){if(b&1)qw=(qw+a)%mod;a=(a+a)%mod;b>>=1;}return qw;}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i].x>>p[i].y,p[i].id=i;
	sort(p+1,p+1+n,[&](node a,node b){return a.x<b.x;});
	for(int i=1;i<=n;i++)a[i]=p[i].x;
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		auto [id,x,r]=p[i];
		int fa=lower_bound(a+1,a+1+n,x-r)-a;
		int fb=upper_bound(a+1,a+1+n,x+r)-a-1;
		query(1,1,n,fa,fb,i);
	}
	for(int i=1;i<=tot;i++)
		l[i]=n,r[i]=1;
	for(int i=1;i<=tot;i++)
	{	
		if(!dfn[i])
			tarjan(i);
	}
	for(int x=1;x<=tot;x++){
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(col[x]!=col[y]){
				v[col[y]].push_back(col[x]),in[col[x]]++;
			}
		}
	}		
	queue<int>q;
	for(int i=1;i<=num;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			l[y]=min(l[y],l[x]);
			r[y]=max(r[y],r[x]);
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++)
	{
		int x=p[i].id;
		ll now=r[col[i]]-l[col[i]]+1;
		ans=(ans+mull(x,now))%mod;
	}
	cout<<ans<<endl;
}
signed  main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
/*
4
1 1
3 1
5 1
10 20

*/