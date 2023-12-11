/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
#define endl "\n"
#define int long long
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e5;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,np,nc,m,s,t;
inline void read(int &x){
   int s = 0, w = 1; char ch = getchar();
   while(ch < '0' || ch > '9'){ if(ch == '-') w = -1; ch = getchar(); }
   while(ch >= '0' && ch <= '9') s = s * 10 + ch - '0', ch = getchar();
   x = s*w;
   return ;
}
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*(n+2));
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
	memset(dep+1,0,sizeof(int)*(n+2));
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
void solve()
{
	while(cin>>n)
	{
		//read(n);
		read(np);
		read(nc);
		read(m);
		init();
		//cout<<n<<" "<<np<<" "<<nc<<" "<<m<<endl;
		s=n+1;
		t=n+2;
		for(int i=1;i<=m;i++)
		{
			int x,y,w;
			read(x);x++;
			read(y);y++;
			read(w);
			add(x,y,w);
			add(y,x,0);
		}
		for(int i=1;i<=np;i++)
		{
			int x,w;
			read(x);read(w);
			x++;
			add(s,x,w);
			add(x,s,0);
		}
		for(int i=1;i<=nc;i++)
		{
			int x,w;
			read(x);read(w);
			x++;
			add(x,t,w);
			add(t,x,0);
		}
		printf("%lld\n",DINIC(s,t));
	}
}
signed main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}