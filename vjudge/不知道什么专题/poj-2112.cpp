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
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dep[maxn];
int n,m,k,s,t;
void init(){
	cnt=1;
	memset(head+1,0,sizeof(int)*t);
}
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
bool bfs(int s,int t)
{
	memset(dep+1,0,sizeof(int)*t);
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
int mp[300][300];
bool check(int mid)
{
	init();
	for(int i=1;i<=n;i++)
	{
		add(i,t,k);
		add(t,i,0);
	}
	for(int i=1;i<=m;i++)
	{
		add(s,i+n,1);
		add(i+n,s,0);
	}
	for(int i=n+1;i<=n+m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(mp[i][j]<=mid)
			{
				add(i,j,1);
				add(j,i,0);
			}
		}
	}
	int ans=DINIC(s,t);

	if(ans==m)return 1;
	else return 0;
}
void solve()
{
	cin>>n>>m>>k;
	s=n+m+1;
	t=n+m+2;
	int l=0,r=0,ans;
	for(int i=1;i<=n+m;i++)
		for(int j=1;j<=n+m;j++){
			cin>>mp[i][j];
			if(mp[i][j]==0)mp[i][j]=INF;
		}
	for(int k=1;k<=n+m;k++)
		for(int i=1;i<=n+m;i++) 
			for(int j=1;j<=n+m;j++)
				mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	r=ans=1e9;
	while(l<r-1)
	{
		int mid=(l+r)>>1;
		if(check(mid))ans=mid,r=mid;
		else l=mid;
	}
	if(check(ans-1))cout<<ans-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}