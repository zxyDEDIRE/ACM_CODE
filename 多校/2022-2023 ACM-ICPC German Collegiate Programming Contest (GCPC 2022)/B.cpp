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
bool su(int x)
{
	if(x==1)return 0;
	if(x==2||x==3)return 1;
	if(x%6!=5&&x%6!=1)return 0;
	int tmp=sqrt(x);
	for(int i=5;i<=tmp;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1;
}
vector<int>v[maxn];
bitset<maxn>vis;
int p[maxn];
int n;
void dfs(int x,int op=0)
{
	vis[x]=1;
	if(op==0)
		Flow::Add(Flow::s,x,1);
	else
		Flow::Add(x,Flow::t,1);
	for(auto y:v[x])
	{
		if(op==0)
			Flow::Add(x,y,1);
		else
			Flow::Add(y,x,1);
		if(vis[y])continue;
		vis[y]=1;
		dfs(y,op^1);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	sort(p+1,p+1+n,[&](int a,int b){return a>b;});
	for(int i=n;i>1;i--){
		if(p[i]==1&&p[i-1]==1)n--;
		else break;
	}

	Flow::init();
	Flow::s=n+1;
	Flow::t=n+2;
	Flow::tot=n+2;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(su(p[i]+p[j])){
				v[i].push_back(j);
				v[j].push_back(i);
			}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	cout<<n-Flow::DINIC()<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
4
1 1 1 3
*/