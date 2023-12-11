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
struct Q{
	int id,dis;
	bool operator<(const Q &a)const{
		return a.dis<dis;
	}
};
struct node{
	int x,y,h;
}p[maxn];
struct Edge{
	int to,next,w;
}edge[maxn];
bitset<maxn>vis;
int head[maxn],cnt;
int f[maxn][3];
int dis[maxn];
int val[maxn];
int mi[maxn];
int ff[maxn];
int n,m,tot;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	vis.reset();
	priority_queue<Q>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
}
int find(int r){
	return ff[r]=ff[r]==r?ff[r]:find(ff[r]);
	// return ff[r]==r?ff[r]:find(ff[r]);
}
void dfs(int x,int F)
{
	mi[x]=dis[x];
	f[x][0]=F;
	for(int i=1;(1<<i)<=tot;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		dfs(y,x);
		mi[x]=min(mi[x],mi[y]);
	}
}
void kruskal()
{
	memset(head+1,0,sizeof(int)*(cnt+10));cnt=0;
	sort(p+1,p+1+m,[&](node a,node b){
		return a.h>b.h;
	});
	for(int i=1;i<=n;i++)
		ff[i]=i;
	tot=n;
	for(int i=1;i<=m;i++)
	{
		auto [x,y,h]=p[i];
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			++tot;
			ff[fa]=ff[fb]=ff[tot]=tot;
			val[tot]=h;
			add(tot,fa,0);
			add(tot,fb,0);
		}
	}
	for(int i=n+1;i<=tot;i++)
		dis[i]=INF;
	dfs(tot,0);
}
void init()
{
	memset(head,0,sizeof(int)*(cnt+10));
	for(int i=1;i<=n;i++)
		for(int j=0;j<=20;j++)
			f[i][j]=0;
	
	cnt=0;
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y,w,h;
		cin>>x>>y>>w>>h;
		add(x,y,w);
		add(y,x,w);
		p[i]={x,y,h};
	}
	dij(1);
	kruskal();
	// for(int i=1;i<=n;i++)
	// 	cout<<dis[i]<<" ";cout<<endl;
	// for(int i=1;i<=tot;i++)
	// 	cout<<mi[i]<<" ";cout<<endl;
	int q,k,s;
	int last=0;
	cin>>q>>k>>s;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		x=(x+k*last-1)%n+1;
		y=(y+k*last)%(s+1);
		for(int i=22;i>=0;i--)
			if(val[f[x][i]]>y&&f[x][i])
				x=f[x][i];
		last=mi[x];
		cout<<last<<endl;
	}
}
signed main(){
// freopen("C:\\Users\\tob\\Desktop\\aa\\return5.in","r",stdin);
// freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}