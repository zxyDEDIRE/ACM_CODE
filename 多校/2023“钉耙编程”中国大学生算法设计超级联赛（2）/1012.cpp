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
const int N=3e3+10;
vector<int>p[N];
int a[N];
int k;
void solve()
{
	init();
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[i].clear();
	s=++tot;
	t=++tot;
	for(int i=1;i<=m;i++)
	{
		int x,y,_x,_y;
		cin>>x>>y;
		if(p[x].size()==0)
		{
			_x=++tot;
			add(s,_x,1);
			add(_x,s,0);
		}
		else
		{
			_x=++tot;
			add(p[x].back(),_x,a[x]);
			add(_x,p[x].back(),0);
		}
		if(p[y].size()==0)
		{
			_y=++tot;
			add(s,_y,1);
			add(_y,s,0);
		}
		else
		{
			_y=++tot;
			add(p[y].back(),_y,a[y]);
			add(_y,p[y].back(),0);
		}
		p[x].push_back(_x);
		p[y].push_back(_y);

		add(_x,_y,1);
		add(_y,_x,1);
	}
	for(int i=1;i<=k;i++)
	{
		int x,_x;
		cin>>x;
		if(p[x].size()==0)
		{
			_x=++tot;
			add(s,_x,1);
			add(_x,s,0);
		}
		else
		{
			_x=++tot;
			add(p[x].back(),_x,a[x]);
			add(_x,p[x].back(),0);
		}

		add(_x,t,a[x]);
		add(t,_x,0);
	}

	int ans=DINIC(s,t);
	cout<<ans<<endl;

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