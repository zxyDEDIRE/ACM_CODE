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
const int maxn=1e7;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*tot);
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
int p[maxn];
void solve()
{
	cin>>n;
	init();
	s=++tot;
	t=++tot;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		p[i]=++tot;
		add(s,p[i],x);
		add(p[i],s,0);
		sum+=x;
	}
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		add(p[i],t,x);
		add(t,p[i],0);
		sum+=x;
	}
	cin>>m;
	while(m--)
	{
		int k,c1,c2,a=++tot,b=++tot;
		cin>>k>>c1>>c2;
		sum+=c1+c2;
		add(s,a,c1);
		add(a,s,0);

		add(b,t,c2);
		add(t,b,0);

		for(int i=1;i<=k;i++)
		{
			int x;cin>>x;
			add(a,p[x],INF);
			add(p[x],a,0);

			add(p[x],b,INF);
			add(b,p[x],0);
		}
	}
	cout<<sum-DINIC(s,t)<<endl;
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);

		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}