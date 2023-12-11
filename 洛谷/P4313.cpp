/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dep[maxn];
int n,m,s,t,tot;
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
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int N=200;
int in[N][N];
void solve()
{
	cin>>n>>m;
	init();
	s=++tot;
	t=++tot;
	int sum=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			in[i][j]=++tot;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			sum+=x;
			add(s,in[i][j],x);
			add(in[i][j],s,0);
		}
	}
		
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			sum+=x;
			add(in[i][j],t,x);
			add(t,in[i][j],0);
		}
	}
		
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{	
			int x;cin>>x;
			sum+=x;
			++tot;
			add(s,tot,x);
			add(tot,s,0);

			add(tot,in[i][j],INF);
			add(in[i][j],tot,0);
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||y<1||x>n||y>m)continue;
				add(tot,in[x][y],INF);
				add(in[x][y],tot,0);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x;cin>>x;
			sum+=x;
			++tot;
			add(tot,t,x);
			add(t,tot,0);

			add(in[i][j],tot,INF);
			add(tot,in[i][j],0);
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x<1||y<1||x>n||y>m)continue;
				add(in[x][y],tot,INF);
				add(tot,in[x][y],0);
			}
		}
	}
	int ans=DINIC(s,t);
	cout<<sum-ans<<endl;
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