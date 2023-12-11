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
#define int long long
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
int f(int x,int y)
{
	return m*(x-1)+y;
}
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
bool vis[400][400];
int mp[400][400];
void solve()
{
	cin>>m>>n>>k;
	if(k&1){
		cout<<"NO"<<endl;
		return ;
	}
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[x][y]=1;
	}
	s=n*m+100;
	t=n*m+200;
	init();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])continue;

			if((i+j)%2==1)
			{
				add(s,f(i,j),1);
				add(f(i,j),s,0);
				for(int ii=0;ii<4;ii++)
				{
					int x=i+dx[ii];
					int y=j+dy[ii];
					if(x<1||x>n||y<1||y>m)continue;
					add(f(i,j),f(x,y),1);
					add(f(x,y),f(i,j),0);
				}
			}
			else
			{
				add(f(i,j),t,1);
				add(t,f(i,j),0);
			}
		}
	}
	int ans=DINIC(s,t);
	if((ans*2+k)==n*m)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}