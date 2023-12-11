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
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*tot);
	queue<int>q;
	dep[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dep[y]==0&&w>0)
				q.push(y),dep[y]=dep[x]+1;
		}
	}
	return false;
}
int dfs(int x,int flow,int t)
{
	if(x==t)return flow;
	int out=flow;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		int w=edge[i].w;
		if(w!=0&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(out,w),t);
			edge[i].w-=tmp;
			edge[i^1].w+=tmp;
			out-=tmp;
			if(!out)break;
		}
	}
	if(out==flow)dep[x]=0;
	return flow-out;
}
int DINIC(int s,int t)
{
	int ans=0;
	while(bfs(s,t))
		ans+=dfs(s,INF,t);
	return ans;
}
vector<pii>v[maxn];
int id[maxn][20];
int f[maxn][20];
int val[maxn];
int d[maxn];
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;f[x][0]=fa;
	for(int i=1;i<=15;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	for(auto [y,w]:v[x])
		if(y!=fa)
			val[y]=w,dfs(y,x);
}
int LCA(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for (int j = 0, D = d[x] - d[y]; D; ++j, D >>= 1)
		if (D & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 15; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
}
int find(int x,int y){
    if(id[x][y])return id[x][y];
    id[x][y]=++tot;
    if(!y)
    {
    	// F.add(tot, t, val[x]);

    	add(tot,t,val[x]);
    	add(t,tot,val[x]);
    }
    else {
    	int to;

    	to=find(x,y-1);
    	add(id[x][y],to,INF);
    	add(to,id[x][y],0);

    	to=find(f[x][y-1],y-1);
    	add(id[x][y],to,INF);
    	add(to,id[x][y],0);

        // F.add(id[x][y], find(x,y-1), inf);
        // F.add(id[x][y], find(fat[x][y-1],y-1), inf);
    }
    return id[x][y];
}

void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
		v[y].push_back({x,w});
	}
	s=1;t=2;tot=2;
	int ans=0;
	dfs(1,0);
	while(m--)
	{
		int x,y,a,b;
		cin>>x>>y>>a>>b;a-=b;
		if(a<=0)continue;
		ans+=a;
		int now=++tot;
		add(s,tot,a);
		add(tot,s,0);
		int lca=LCA(x,y);
		for(int i=14;i>=0;i--)
			if((d[x]-d[lca])>>i&1)
			{
				int to=find(x,i);
				add(now,to,INF);
				add(to,now,0);
				x=f[x][i];
			}
		for(int i=14;i>=0;i--)
			if((d[y]-d[lca])>>i&1)
			{
				int to=find(y,i);
				add(now,to,INF);
				add(to,now,0);
				y=f[y][i];
			}
	}
	ans-=DINIC(s,t);
	cout<<ans<<endl;
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