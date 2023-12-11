#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=1e5;
const int N=111;
map<int,pair<int,int> >MP;
char mp[N][N];
int col[N][N];
int num[N];
int col_tot;
int n,m;

struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
bitset<maxn>vis,duo;
int cut[maxn];
stack<int>s; 
int ans=0;

void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void dfs1(int x,int y,int k)
{
	col[x][y]=k;
	if(mp[x][y]=='@')num[k]++;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]=='#')continue;
		if(mp[xx][yy]=='X')continue;
		if(col[xx][yy])continue;
		dfs1(xx,yy,k);
	}
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	int num=0;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			num++;
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(low[y]>=dfn[x])
			{
				cut[x]=1;
				int v;
				do{
					v=s.top();s.pop();
				}while(v!=y);
			}
		}
		else if(vis[x]&&dfn[y]<dfn[x]&&i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
	if(fa==0&&num==1)cut[x]=0;
}
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	if(cut[x])
	{
		if(duo[x])
		{
			pair<int,int>pii = MP[x];
			int _x=pii.first;
			int _y=pii.second;
			for(int i=0;i<4;i++)
			{
				int xx=_x+dx[i];
				int yy=_y+dy[i];
				if(mp[xx][yy]=='@'&&!vis[col[xx][yy]])
					ans++;
			}
		}
		else
		{
//			cout<<"ans :";
//			cout<<x<<" "<<num[x]<<endl;
			ans+=num[x];
			for(int i=head[x];i;i=edge[i].next)
			{
				int y=edge[i].to;
				dfs(y);
			}
		}
		return ;
	}
	else
	{
		ans+=num[x];
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			dfs(y);
		}
	}
}
void solve()
{
	vis.reset();
	duo.reset();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			col[i][j]=0;
		}
	for(int i=1;i<=indx;i++)
		dfn[i]=low[i]=cut[i]=num[i]=0;
	for(int i=1;i<=cnt;i++)
		head[i]=0;
	cnt=0;
	indx=0;
	col_tot=0;
	ans=0;
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]!='X'&&mp[i][j]!='#'&&col[i][j]==0)
				col_tot++,dfs1(i,j,col_tot);
//	for(int i=1;i<=n;i++)
//	{
//		for(int j=1;j<=m;j++)
//			cout<<col[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mp[i][j]!='X')continue;
			col[i][j]=++col_tot;
			int now=col_tot;
			duo[now]=1;
			MP[col_tot]=make_pair(i,j);
			vector<int>p;
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				if(col[x][y])p.push_back(col[x][y]);
			}
			for(int I=0;I<p.size();I++){
				for(int J=I+1;J<p.size();J++){
					add(p[I],now);
					add(p[J],now);
					add(now,p[I]);
					add(now,p[J]);
//					cout<<now<<" "<<p[I]<<endl;
//					cout<<now<<" "<<p[J]<<endl;
				}
			}
		}
	}
	tarjan(1,0);
//	for(int i=1;i<=col_tot;i++)
//		cout<<cut[i]<<" ";cout<<endl;
	int sx,sy;
	for(int i=1;i<=n;i++)
	{
		if(mp[i][1]=='.')sx=i,sy=1;
		if(mp[i][m]=='.')sx=i,sy=m; 
	}
	for(int i=1;i<=m;i++)
	{
		if(mp[1][i]=='.')sx=1,sy=i;
		if(mp[n][i]=='.')sx=n,sy=i;
	}
	vis.reset();
	dfs(col[sx][sy]);
	cout<<ans<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	while(cin>>n>>m)
//		cin>>n>>m;
		solve();
}
