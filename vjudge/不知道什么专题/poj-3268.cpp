/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<algorithm>
#include<iostream>
#include<bitset>
#include<queue>
using namespace std;
#define endl "\n"
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e3+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
	node():id(0),dis(0){};
	node(int a,int b):id(a),dis(b){};
};
int dis_a[maxn][maxn];
int dis_b[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];
bitset<maxn>vis;
int n,m,s;
void dij_1(int s)
{
	priority_queue<node>q;
	vis.reset();
	q.push(node(s,0));
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int y=1;y<=n;y++)
		{
			if(dis_a[s][y]>=dis_a[s][x]+a[x][y])
			{
				dis_a[s][y]=dis_a[s][x]+a[x][y];
				q.push(node(y,dis_a[s][y]));
			}
		}
	}
}
void dij_2(int s)
{
	priority_queue<node>q;
	vis.reset();
	q.push(node(s,0));
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.id;
		if(vis[x])continue;
		vis[x]=1;
		for(int y=1;y<=n;y++)
		{
			if(dis_b[s][y]>=dis_b[s][x]+b[x][y])
			{
				dis_b[s][y]=dis_b[s][x]+b[x][y];
				q.push(node(y,dis_b[s][y]));
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				dis_a[i][j]=dis_b[i][j]=a[i][j]=b[i][j]=INF;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		a[x][y]=min(a[x][y],w);
		b[y][x]=min(b[y][x],w);
	}
	dij_1(s);
	dij_2(s);
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,dis_a[s][i]+dis_b[s][i]);
	cout<<ma<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}