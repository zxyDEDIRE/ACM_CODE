/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int maxn=1e6+10;
struct node{
	int id,dis;
	bool operator<(const node&a)const{return a.dis<dis;}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],p[maxn],prime[maxn];
bitset<maxn>vis,ok;
vector<int>v[maxn];
vector<int>ans;
int n,now,S,T;
void add(int from,int to)
{
	edge[++cnt].w=1;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void init()
{
	ok[1]=true;
	int N=3e5+100;
	for(int i=2;i<=N;i++)
	{
		if(ok[i]==false)prime[++prime[0]]=i;
		for(int j=1;j<=prime[0]&&prime[j]*i<=N;j++){
			ok[i*prime[j]]=true;
			if(i%prime[j]==0)break;
		} 
	}
}
void dij(int s,int t)
{
	memset(dis,inf,sizeof(dis));
	vis.reset();
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(x==t)return ;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		// for(auto y:v[x])
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
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
	for(int a=1,x;a<=n;a++)
	{
		scanf("%d",&x);
		for(int i=1;prime[i]*prime[i]<=x;i++)
		{
			if(x%prime[i]==0)
			{
				while(x%prime[i]==0)x/=prime[i];
				// v[a].push_back(prime[i]+n);
				// v[prime[i]+n].push_back(a);
				add(a,prime[i]+n);
				add(prime[i]+n,a);
			}
		}
		if(!ok[x])
		{
			add(a,x+n);
			add(x+n,a);
			// v[a].push_back(x+n);
			// v[x+n].push_back(a);
		}
	}
	scanf("%d%d",&S,&T);now=T;
	dij(S,T);
	while(now!=S)
	{
		if(now<=n)ans.push_back(now);
		now=p[now];
	}ans.push_back(S);
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