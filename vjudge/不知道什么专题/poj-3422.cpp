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
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
#define int long long
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
struct node{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
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
	//cout<<maxf<<" "<<maxc<<endl;
	return maxc;
}
const int dx[]={0,1};
const int dy[]={1,0};
int mp[100][100];
int in[100][100];
int out[100][100];
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			in[i][j]=++tot;
			out[i][j]=++tot;
			add(in[i][j],out[i][j],1,-mp[i][j]);
			add(out[i][j],in[i][j],0,mp[i][j]);
		}
	s=++tot;
	t=++tot;
	add(s,in[1][1],1,0);
	add(in[1][1],s,0,0);
	add(out[n][n],t,1,0);
	add(t,out[n][n],0,0);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<2;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(x>n||y>n)continue;
				add(out[i][j],in[x][y],INF,0);
				add(in[x][y],out[i][j],0,0);
			}
		}
	}
	int ans=0;
	while(m--)
	{
		ans+=MCMF(s,t);
		add(s,in[1][1],1,0);
		add(in[1][1],s,0,0);
		add(out[n][n],t,1,0);
		add(t,out[n][n],0,0);
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				add(in[i][j],out[i][j],1,0);
				add(out[i][j],in[i][j],0,0);
			}
		}
	}
	cout<<-ans<<endl;


}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}
