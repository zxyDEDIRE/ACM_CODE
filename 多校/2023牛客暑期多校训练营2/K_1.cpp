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
const int maxn=3e6+100;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
}
void add(int from,int to,int w,int c)
{
	edge[++cnt].w=w;
	edge[cnt].c=c;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool spfa(int s,int t)
{
	memset(dis+1,INF,sizeof(int)*tot);
	memset(last+1,-1,sizeof(int)*tot);
	vis.reset();
	queue<int>q;
	q.push(s);
	dis[s]=0;
	vis[s]=1;
	flow[s]=INF;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			int c=edge[i].c;
			if(w>0&&dis[y]>dis[x]+c)
			{
				dis[y]=dis[x]+c;
				last[y]=i;
				flow[y]=min(flow[x],w);
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
		}
	}
	return last[t]!=-1;
}
int MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	return -maxc;
}
int a[maxn];
int b[maxn];
ll f[maxn][3];
int solve()
{
	cin>>n;
	init();
	s=n*2+1;
	t=n*2+2;
	tot=t;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(i*2,t,1,-a[i]);
		add(t,i*2,0,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		if(x==0)continue;
		add(s,i,1,0);
		add(i,s,0,0);


		add(i,i*2,1,0);
		add(i*2,i,0,0);
		
		if(i-1>=1)
		{
			add(i,(i-1)*2,1,0);
			add((i-1)*2,i,0,0);
		}
		if(i+1<=n)
		{
			add(i,(i+1)*2,1,0);
			add((i+1)*2,i,0,0);
		}
	}
	cout<<MCMF(s,t)<<endl;
	return 0;
}
signed main(){
	solve();
	return 0;
}