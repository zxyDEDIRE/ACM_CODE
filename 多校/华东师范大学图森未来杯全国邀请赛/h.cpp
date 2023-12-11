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
const long long INF=1e18+7;
const int maxn=1e7+100;
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
int a[100000][60];
int dis[maxn];
int n,m,k,tot;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dij(int s,int t)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	priority_queue<node>q;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,DIS]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(dis[y]>dis[x]+edge[i].w)
			{
				dis[y]=dis[x]+edge[i].w;
				q.push({y,dis[y]});
			}
		}
	}
	cout<<dis[t]<<endl;
}
void solve()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			a[i][j]=++tot;
	for(int i=1;i<=n;i++)
	{
		int w;
		cin>>w;
		for(int j=0;j+1<=k;j++)
		{
			add(a[i][j],a[i][j+1],w);
		}
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,c;
		cin>>x>>y>>c;
		for(int j=c;j<=k;j++)
		{
			add(a[x][j],a[y][j-c],0);
			add(a[y][j],a[x][j-c],0);
		}
	}
	int s=++tot;
	int t=++tot;
	add(s,a[1][0],0);
	for(int j=0;j<=k;j++)
		add(a[n][j],t,0);
	dij(s,t);
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
/*
3 2 12
1 10 100
1 2 10
2 3 11

12*1+9*10
12+90
*/