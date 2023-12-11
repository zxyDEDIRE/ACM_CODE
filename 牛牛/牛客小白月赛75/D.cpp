/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=3e6+100;
const int N=1e3+100;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn];
bitset<maxn>vis;
int in[N][N][2];
char mp[N][N];
int n,m,tot;
void add(int from,int to,int w){
	edge[++cnt].w=w;
	edge[cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void ad(int from,int to,int w)
{
	add(from,to,w);
	add(to,from,w);
}
void dij(int s)
{
	for(int i=1;i<=tot;i++)
		dis[i]=INF;
	dis[s]=0;
	vis.reset();


	priority_queue<node>q;
	q.push({s,0});

	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
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

}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=1;k++)
				in[i][j][k]=++tot;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int x=(mp[i][j]=='1'?1:0);
			for(int k=0;k<4;k++)
			{
				int xx=i+dx[k];
				int yy=j+dy[k];
				if(xx<1||yy<1||xx>n||yy>m)continue;
				int y=(mp[xx][yy]=='1'?1:0);
				if(x!=y)
				{
					add(in[i][j][0],in[xx][yy][0],1);
					add(in[i][j][1],in[xx][yy][1],2);
				}
				else
				{
					add(in[i][j][0],in[xx][yy][1],2);
					add(in[i][j][1],in[xx][yy][0],1);
					// add(in[xx][yy][0],in[i][j][1],1);
					// ad(in[i][j][1],in[xx][yy][0],1);
				}
			}
		}
	}
	dij(1);
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++)
	// 		cout<<dis[in[i][j][0]]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++)
	// 		cout<<dis[in[i][j][1]]<<" ";
	// 	cout<<endl;
	// }
	cout<<min(dis[in[n][m][0]],dis[in[n][m][1]])<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
111
010
101

*/