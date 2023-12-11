/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
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
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
bitset<maxn>vis;
int prime[maxn];
vector<int>ans;
int dis[maxn];
bool ok[maxn];
int id[maxn];
int p[maxn];
set<int>s;
int n,tot,now,S,T;
void init()
{
	ok[1]=1;
	int N=3e5+100;
	for(int i=2;i<=N;i++)
	{
		if(!ok[i])prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			ok[i*prime[j]]=1;
			if(i%prime[j]==0)break;
		} 
	}
}
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s,int t)
{
	for(int i=1;i<=tot;i++)dis[i]=inf;
	vis.reset();
	priority_queue<node>q;
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
				p[y]=x;
				q.push({y,dis[y]});
			}
		}
	}
	if(dis[t]==inf){cout<<-1<<endl;exit(0);}
}
void solve()
{
	scanf("%d",&n);
	tot=n;
	for(int a=1,x;a<=n;a++)
	{
		scanf("%d",&x);
		for(int i=1;prime[i]*prime[i]<=x;i++)
		{
			if(x%prime[i]==0)
			{
				while(x%prime[i]==0)x/=prime[i];
				if(!s.count(prime[i]))
					id[prime[i]]=++tot,s.insert(prime[i]);
				add(a,id[prime[i]],1);
				add(id[prime[i]],a,0);
			}
		}
		if(!ok[x]&&x!=1)
		{
			if(!s.count(x))
				id[x]=++tot,s.insert(x);
			add(a,id[x],1);
			add(id[x],a,0);
		}
	}
	scanf("%d%d",&S,&T);
	dij(S,T);
	now=T;
	while(now!=S)
	{
		if(now<=n)ans.push_back(now);
		now=p[now];
	}
	ans.push_back(S);
	printf("%d\n",(int)(ans.size()));
	for(int i=ans.size()-1;i>=0;i--)
		printf("%d ",ans[i]);
	putchar('\n');
}
signed main(){
	init();
	solve();
	return 0;
}