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
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={1,-1,2,-2,2,-2,1,-1};
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
bitset<maxn>vis;
int head[maxn],cnt;
bool ok[40][40];
int mp[40][40];
int in[40][40];
int dis[maxn];
int num[maxn];
int n,m,s,t,tot;
void add(int from,int to,int w)
{
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs(int id,int x,int y)
{
	if(ok[x][y])return ;
	ok[x][y]=1;
	for(int i=0;i<8;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]==2)continue;
		if(ok[xx][yy])continue;
		if(mp[xx][yy]==1)dfs(id,xx,yy);
		else ok[xx][yy]=1,add(id,in[xx][yy],1);
	}
}
void dij(int s)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	priority_queue<node>q;
	q.push({s,0});
	dis[s]=0;
	vis[s]=1;
	num[s]=1;
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		// if(vis[x])continue;
		// vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(!vis[y])dis[y]=dis[x]+w,vis[y]=1,q.push({y,dis[y]});
			if(dis[y]!=dis[x]+w)continue;
			num[y]+=num[x];
			// if(dis[y]>dis[x]+w)
			// {
			// 	dis[y]=dis[x]+w;
			// 	q.push({y,dis[y]});
			// }
		}
	}
}
void spfa(int s)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	queue<int>q;
	q.push(s);
	dis[s]=0;
	num[s]=1;
	vis[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=0;
		// cout<<x<<endl;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			int w=edge[i].w;
			if(dis[y]>dis[x]+w)
			{
				num[y]=num[x];
				dis[y]=dis[x]+w;
				if(!vis[y])
					q.push(y),vis[y]=1;
			}
			else if(dis[y]==dis[x]+w)
				num[y]+=num[x];
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
			in[i][j]=++tot;
			if(mp[i][j]==3)s=in[i][j];
			if(mp[i][j]==4)t=in[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]==0||mp[i][j]==3)
			{
				memset(ok,0,sizeof(ok));
				dfs(in[i][j],i,j);
			}
		}
	}
	// dij(s);
	spfa(s);
	/*for(int x=1;x<=tot;x++)
	{
		cout<<"X "<<x<<endl;
		for(int i=head[x];i;i=edge[i].next)
			cout<<edge[i].to<<" ";
		cout<<endl;
	}*/
	// cout<<"ok"<<endl;
	if(dis[t]==INF)cout<<-1<<endl;
	else
	{
		cout<<dis[t]-1<<endl;
		cout<<num[t]<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1606_5.in","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\a.txt","w+",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
 // fclose(stdin);
 // fclose(stdout);
	return 0;
}