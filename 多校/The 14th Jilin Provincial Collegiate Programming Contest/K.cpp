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
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e18+7;
const int maxn=1e6+100;
struct Edge{
	int to,next,w,c;
}edge[maxn];
int head[maxn],cnt;
int dis[maxn],flow[maxn],last[maxn];
bitset<maxn>vis;
int n,m,s,t,tot;
void init(){
	memset(head+1,0,sizeof(int)*tot);
	cnt=1;
	tot=0;
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
	// memset(dis+1,INF,sizeof(int)*tot);
	// memset(last+1,-1,sizeof(int)*tot);
	for(int i=1;i<=tot;i++)
		dis[i]=INF,last[i]=-1;
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
void MCMF(int s,int t)
{
	int maxf=0,maxc=0;
	while(spfa(s,t))
	{
		if(flow[t]*dis[t]>=0)break;
		maxf+=flow[t];
		maxc+=flow[t]*dis[t];
		// cout<<"flow[t]: "<<flow[t]<<endl;
		// cout<<"flow[t]*dis[t]: "<<flow[t]*dis[t]<<endl;
		// cout<<"maxf: "<<maxf<<endl;
		// cout<<"maxc: "<<maxc<<endl;
		// cout<<endl;
		for(int i=t;i!=s;i=edge[last[i]^1].to)
		{
			edge[last[i]].w-=flow[t];
			edge[last[i]^1].w+=flow[t];
		}
	}
	cout<<-maxc<<endl;
}
const int N=100;
char mp[N][N];
int in[N][N];
int ts_w[N][N];
int gs_num,ts_num;

void dfs_1(int x,int y,int fl,int fa)
{
	if(x<1||y<1||x>n||y>m)return ;
	if(in[x][y]!=fa&&in[x][y]!=0)
	{
		// cout<<x<<" "<<y<<" "<<in[x][y]<<endl;
		add(fa,in[x][y],1,0);
		add(in[x][y],fa,0,0);
	}
	if(mp[x][y]=='.'||mp[x][y]=='L'||mp[x][y]=='R'||mp[x][y]=='U'||mp[x][y]=='D')
		dfs_1(x+dx[fl],y+dy[fl],fl,fa);
}
void dfs_2(int x,int y,int fl,int w,int fa)
{
	if(x<1||y<1||x>n||y>m)return ;
	if(in[x][y]!=fa&&in[x][y]!=0&&mp[x][y]!='R'&&mp[x][y]!='L'&&mp[x][y]!='U'&&mp[x][y]!='D')
	{
		// cout<<x<<" "<<y<<" "<<fl<<endl;
		add(fa,in[x][y],1,w);
		add(in[x][y],fa,0,-w);
	}
	if(mp[x][y]=='.'||mp[x][y]=='L'||mp[x][y]=='R'||mp[x][y]=='U'||mp[x][y]=='D'||(fa==in[x][y]))
		dfs_2(x+dx[fl],y+dy[fl],fl,w,fa);
}
//建反费用边
void solve()
{
	cin>>n>>m>>gs_num>>ts_num;
	init();
	s=++tot;
	t=++tot;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			in[i][j]=0;
		}
	for(int i=1;i<=gs_num;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		in[x][y]=++tot;
		// 宝石连容量为1费用为-vi的边到t
		add(tot,t,1,-w);
		add(t,tot,0,w);
	}
	for(int i=1;i<=ts_num;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		ts_w[x][y]=w;
		in[x][y]=++tot;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j]=='U')
			{
				in[i][j]=++tot;
				add(s,tot,1,0);
				add(tot,s,0,0);
				dfs_1(i,j,3,tot);

				// add(tot,t,1,0);
				// add(t,tot,0,0);
			}
			else if(mp[i][j]=='D')
			{
				in[i][j]=++tot;
				add(s,tot,1,0);
				add(tot,s,0,0);
				dfs_1(i,j,2,tot);

				// add(tot,t,1,0);
				// add(t,tot,0,0);
			}
			else if(mp[i][j]=='L')
			{
				in[i][j]=++tot;
				add(s,tot,1,0);
				add(tot,s,0,0);
				dfs_1(i,j,1,tot);

				// add(tot,t,1,0);
				// add(t,tot,0,0);
			}
			else if(mp[i][j]=='R')
			{
				in[i][j]=++tot;
				add(s,tot,1,0);
				add(tot,s,0,0);
				dfs_1(i,j,0,tot);

				// add(tot,t,1,0);
				// add(t,tot,0,0);
			}

			//const int dx[]={0,0,1,-1,1,-1,1,-1};
			//const int dy[]={1,-1,0,0,1,-1,-1,1};
			else if(mp[i][j]=='^')
			{
				int now=++tot;
				add(in[i][j],now,1,0);
				add(now,in[i][j],0,0);
				dfs_2(i,j,3,ts_w[i][j]*0,now);//U
				dfs_2(i,j,0,ts_w[i][j]*1,now);//R
				dfs_2(i,j,2,ts_w[i][j]*2,now);//D
				dfs_2(i,j,1,ts_w[i][j]*3,now);//L
			}
			else if(mp[i][j]=='v')
			{
				int now=++tot;
				add(in[i][j],now,1,0);
				add(now,in[i][j],0,0);
				dfs_2(i,j,2,ts_w[i][j]*0,now);//D
				dfs_2(i,j,1,ts_w[i][j]*1,now);//L
				dfs_2(i,j,3,ts_w[i][j]*2,now);//U
				dfs_2(i,j,0,ts_w[i][j]*3,now);//R
			}
			else if(mp[i][j]=='<')
			{
				int now=++tot;
				add(in[i][j],now,1,0);
				add(now,in[i][j],0,0);
				dfs_2(i,j,1,ts_w[i][j]*0,now);//L
				dfs_2(i,j,3,ts_w[i][j]*1,now);//U
				dfs_2(i,j,0,ts_w[i][j]*2,now);//R
				dfs_2(i,j,2,ts_w[i][j]*3,now);//D
			}
			else if(mp[i][j]=='>')
			{
				int now=++tot;
				add(in[i][j],now,1,0);
				add(now,in[i][j],0,0);
				dfs_2(i,j,0,ts_w[i][j]*0,now);//R
				dfs_2(i,j,2,ts_w[i][j]*1,now);//D
				dfs_2(i,j,1,ts_w[i][j]*2,now);//L
				dfs_2(i,j,3,ts_w[i][j]*3,now);//U
			}
		}
	}
	MCMF(s,t);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 7 3 3
R..<..x
R^....x
R.<...x
1 7 5
2 7 5
3 7 5

1 4 0
2 2 1
3 3 1



*/