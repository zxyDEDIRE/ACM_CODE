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
// const int maxn=1e6+100;
struct Edge{int to,next;};
vector<int>head,low,dfn;
vector<array<int,18>>f;
vector<vector<int>>v;
vector<int>dis,dep,id;
vector<Edge>edge;
stack<int>s;
int cnt,indx,tot,id_cnt;
int n,m;
void add(int from,int to){
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	v.resize(n*2+2);
	while(s.size())s.pop();
	head.resize(n+1,0);
	edge.resize(m*2+10);
	low.resize(n+2,0);
	dfn.resize(n+2,0);
	id_cnt=0;
	cnt=1;
	tot=n;
	indx=0;

	// f.resize(n*2+1);
	// dis.resize(n*2+1);
	// dep.resize(n*2+1);
	// id.resize(n*2+1);
}
void tarjan(int x,int fa=0)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				tot++;
				v[x].push_back(tot);
				v[tot].push_back(x);
				int r;
				do{
					r=s.top();s.pop();
					v[tot].push_back(r);
					v[r].push_back(tot);
				}while(r!=y);
			}
		}
		else if(i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
}
void dfs(int x,int fa=0)
{
	id[x]=++id_cnt;
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=1;i<=17;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dis[y]=dis[x]+(y<=n);
		dfs(y,x);
	}
}
int lca(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for (int j = 0, d = dep[x] - dep[y]; d; ++j, d >>= 1)
		if (d & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 17; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);

	f.resize(tot+2);
	dis.resize(tot+2);
	dep.resize(tot+2);
	id.resize(tot+2);

	dfs(1);
	int q;cin>>q;

	// for(int i=1;i<=id_cnt;i++)
	// 	cout<<"i:"<<i<<" dis[i]:"<<dis[i]<<" id[i]:"<<id[i]<<" fa[i]:"<<f[i][0]<<endl;

	while(q--)
	{
		int k;
		cin>>k;
		vector<int>p(k);
		for(int i=0;i<k;i++)
			cin>>p[i];
		sort(p.begin(),p.end(),[&](int a,int b){
			return id[a]<id[b];
		});
		int ans=0;
		for(int i=0;i<k;i++) 
		{
			int x=p[i];
			int y=p[(i+1)%k];
			ans+=dis[x]+dis[y]-dis[lca(x,y)]*2;
			// cout<<"x:"<<x<<" y:"<<y<<" lca:"<<lca(x,y)<<" dis:"<<dis[x]+dis[y]-dis[lca(x,y)]*2<<endl;
		}
		if(lca(p[0],p[k-1])<=n)ans+=2;
		cout<<ans/2-k<<endl;
	}
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
7 6
1 2
1 3
2 4
2 5
3 6
3 7
1
3 2 3 4
*/