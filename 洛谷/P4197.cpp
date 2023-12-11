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
const int maxn=1e6+100;
struct node{
	int x,y,w;
	bool operator<(const node&a)const{
		return a.w>w;
	}
}a[maxn];
struct Edge{
	int to,next,w;
}edge[maxn];
int T[maxn],L[maxn<<1],R[maxn<<1],sum[maxn<<1],indx;
vector<int>v;
int f[maxn][23];
int head[maxn],cnt;
int val[maxn];
int l[maxn],r[maxn];
int p[maxn];
int h[maxn];
int b[maxn];
int n,m,q,tot;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
void dfs(int x,int fa)
{
	if(x<=n)
		v.push_back(h[x]),l[x]=r[x]=v.size()-1;
	f[x][0]=fa;
	for(int i=1;(1<<i)<=tot;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		dfs(y,x);
		l[x]=min(l[x],l[y]);
		r[x]=max(r[x],r[y]);
	}
}
void kruskal()
{
	// for(int i=1;i<=n;i++)
	// 	l[i]=i,r[i]=i;
	for(int i=1;i<=n;i++)
		p[i]=i;
	tot=n;
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
	{
		auto [x,y,h]=a[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			++tot;
			p[fa]=p[fb]=p[tot]=tot;
			add(tot,fa,0);
			add(tot,fb,0);
			val[tot]=h;
			l[tot]=INF;
			r[tot]=0;
		}
	}
	
}
int build(int l,int r)
{
	int rt=++indx;
	if(l<r)
	{
		int mid=(l+r)>>1;
		L[rt]=build(l,mid);
		R[rt]=build(mid+1,r);
	}
	return rt;
}
int update(int pre,int l,int r,int x)
{
	int rt=++indx;
	L[rt]=L[pre];R[rt]=R[pre];
	sum[rt]=sum[pre]+1;
	if(l<r)
	{
		int mid=(l+r)>>1;
		if(x<=mid)L[rt]=update(L[pre],l,mid,x);
		else R[rt]=update(R[pre],mid+1,r,x);
	}
	return rt;
}
int query(int u,int v,int l,int r,int k)
{
	if(l==r)return l;
	int x=sum[L[v]]-sum[L[u]];
	int mid=(l+r)>>1;
	if(x>=k)return query(L[u],L[v],l,mid,k);
	else return query(R[u],R[v],mid+1,r,k-x);
}
void build()
{
	for(int i=1;i<=n;i++)
		b[i]=v[i];
	sort(b+1,b+1+n);
	m=unique(b+1,b+1+n)-b-1;
	T[0]=build(1,m);
	for(int i=1;i<=n;i++)
	{
		v[i]=lower_bound(b+1,b+1+m,v[i])-b;
		T[i]=update(T[i-1],1,m,v[i]);
	}
}
void solve()
{
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		cin>>h[i];
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[i]={x,y,w};
	}
	kruskal();
	v.push_back(0);
	dfs(tot,0);

	int last=0;
	build();
	while(q--)
	{
		int x,y,k;
		cin>>x>>y>>k;
		x=(x^last)%n+1;
		k=(k^last)%n+1;
		y=(y^last);
		for(int i=22;i>=0;i--)
			if(f[x][i]&&val[f[x][i]]<=y)
				x=f[x][i];
		int li=l[x];
		int ri=r[x];
		int len=ri-li+1;
		// cout<<"********************"<<endl;
		// cout<<li<<" "<<ri<<" "<<len<<" "<<k<<" "<<len-k+1<<endl;
		// for(int i=li;i<=ri;i++)
		// 	cout<<v[i]<<" ";cout<<endl;
		if(len<k){
			cout<<-1<<endl;
			last=0;
		}
		else
		{
			int p=query(T[li-1],T[ri],1,m,len-k+1);
			cout<<(last=b[p])<<"\n";
		}
		// cout<<"********************"<<endl;
	}
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
/*
8 9 4 1 7 6 5 2 3 10
*/