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
#include<cmath>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
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
	memset(dep+1,0,sizeof(int)*t);
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
double a[maxn],b[maxn];
int u,v;
void solve()
{
	while(cin>>n>>m>>u>>v)
	{
		s=n+m+1;
		t=n+m+2;
		init();
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			add(s,i,1);
			add(i,s,0);
		}
		for(int i=n+1;i<=n+m;i++){
			cin>>a[i]>>b[i];
			add(i,t,1);
			add(t,i,0);
		}
		
		for(int i=1;i<=n;i++)
		{
			for(int j=n+1;j<=n+m;j++)
			{
				int dis=((a[i]-a[j])*(a[i]-a[j])+(b[i]-b[j])*(b[i]-b[j]));
				if(dis<u*v*u*v)
				{
					add(i,j,1);
					add(j,i,0);
				}
			}
		}
		cout<<n-DINIC(s,t)<<endl;
	}
	
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}