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
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
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
void MCMF(int s,int t)
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
	cout<<-maxc<<endl;
}
const int N=1000;
int in[maxn];
pii p[maxn];
int k,ma;
void solve()
{
	cin>>n>>k;
	init();
	for(int i=1;i<=n;i++)
	{
		cin>>p[i].first>>p[i].second;
		if(p[i].first>p[i].second)
			swap(p[i].first,p[i].second);
		ma=max(ma,p[i].second);
	}
	for(int i=0;i<=ma;i++)
		in[i]=++tot;
	s=++tot;
	t=++tot;

	add(s,in[0],k,0);
	add(in[0],s,0,0);

	add(in[ma],t,k,0);
	add(t,in[ma],0,0);

	for(int i=1;i<=ma;i++)
	{
		add(in[i-1],in[i],k,0);
		add(in[i],in[i-1],0,0);
	}

	for(int i=1;i<=n;i++)
	{
		add(in[p[i].first],in[p[i].second],1,p[i].first-p[i].second);
		add(in[p[i].second],in[p[i].first],0,p[i].second-p[i].first);
	}
	MCMF(s,t);




}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}