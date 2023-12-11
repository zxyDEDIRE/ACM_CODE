/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
#define ing long long
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
const int maxn=1e7;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dep[maxn];
int p[maxn];
int n,m,s,t,tot;
void init(){
	cnt=1;
	//memset(head+1,0,sizeof(int)*tot);
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
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(x==t)return true;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(w&&!dep[y])
				dep[y]=dep[x]+1,q.push(y);
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
		if(w&&dep[y]==dep[x]+1)
		{
			int tmp=dfs(y,min(w,out),t);
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
	while(bfs(s,t)){
		ans+=dfs(s,INF,t);
	}
	return ans;
}
void solve()
{
	cin>>m>>n;
	cin>>n>>m;
	s=n+m+1;
	t=n+m+2;
	tot=t;
	init();
	for(int i=1;i<=m;i++)
	{
		int x;cin>>x;
		add(s,i+n,x);
		add(i+n,s,0);
		p[i]=i+n;
	}
	for(int i=1;i<=n;i++)
	{
		int k;cin>>k;
		int in=i;
		while(k--)
		{
			int x;cin>>x;
			add(p[x],i,INF);
			add(i,p[x],0);

			// if(p[x]==x+n)p[x]=i;
			p[x]=++tot;
			add(i,p[x],INF);
			add(p[x],i,0);
		}
		int x;cin>>x;
		add(i,t,x);
		add(t,i,0);
		//cout<<p[1]<<endl;
	}
	cout<<DINIC(s,t)<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}
/*
3 1 10
0 2 10
0 2 7
*/