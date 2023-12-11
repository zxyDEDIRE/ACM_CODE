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
const int N=3000+200;
namespace Flow{
	struct Edge{
		int to,next,w;
	}edge[maxn];
	int head[maxn],cnt=1;
	int dep[maxn];
	int s,t,tot;
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
	void Add(int u,int v,int w)
	{
		add(u,v,w);
		add(v,u,0);
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
	int DINIC()
	{
		int ans=0;
		while(bfs(s,t))
			ans+=dfs(s,INF,t);
		return ans;
	}
}
vector<pii>v[maxn];
int w[N][N];
int a[N];
int co[N];
int n;
void dfs(int s,int x,int fa)
{
	for(auto [y,c]:v[x])
	{
		if(y==fa)continue;
		w[s][y]=max(w[s][y],c);
		dfs(s,y,x);
	}
}
void solve()
{
	cin>>n;
	Flow::init();
	Flow::s=n+1;
	Flow::t=n+2;
	Flow::tot=n+2;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cin>>co[i];
		if(co[i]==0)
		{
			Flow::Add(Flow::s,i,0);
		}
		else
		{
			Flow::Add(i,Flow::t,-co[i]);
		}
	}
	for(int i=1;i<n;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
	}
	for(int i=1;i<=n;i++)
		dfs(i,i,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			int c=w[i][j];
			++Flow::tot;
			Flow::Add(Flow::s,Flow::tot,c);


			Flow::Add(Flow::tot,i,INF);
			Flow::Add(Flow::tot,j,INF);
		}
	}
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			sum+=w[i][j];
	int ans=Flow::DINIC();
	cout<<sum-ans<<endl;
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