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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=50;
struct node{int x,y,step;};
bool vis[N][N];
int dis[N][N];
char mp[N][N];
int n,m;
int bfs(int sx,int sy,int _sx,int _sy)
{
	memset(dis,inf,sizeof(dis));
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push({sx,sy});
	q.push({_sx,_sy});
	dis[sx][sy]=dis[_sx][_sy]=0;
	vis[sx][sy]=vis[_sx][_sy]=1;
	while(!q.empty())
	{
		auto [x,y,step]=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]!='#')continue;
			if(vis[xx][yy])continue;
			vis[xx][yy]=1;
			dis[xx][yy]=dis[x][y]+1;
			q.push({xx,yy,dis[xx][yy]});
		}
	}
	int mi=0;
	// cout<<sx<<" "<<sy<<" "<<_sx<<" "<<_sy<<endl;
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 		if(dis[i][j]==inf)cout<<"* ";
	// 		else cout<<dis[i][j]<<" ";
	// 	cout<<endl;
	// }
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='#')
				mi=max(mi,dis[i][j]);
	// cout<<mi<<endl;
	// cout<<endl;
	return mi;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	int ans=inf;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int I=i;I<=n;I++)
				for(int J=1;J<=m;J++)
					if(mp[I][J]=='#'&&mp[i][j]=='#'){
						// cout<<i<<" "<<j<<" "<<I<<" "<<J<<" "<<endl;
						int x=bfs(i,j,I,J);
						// cout<<x<<endl;
						ans=min(ans,x);
						// bfs(i,j,I,J);
						// cout<<endl;
					}
	if(ans==inf)cout<<-1<<endl;
	else cout<<ans<<endl;
	// cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	for(int i=1;i<=__;i++){
		cout<<"Case "<<i<<": ";
		solve();
	}
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 3
18

2 10
21#1231#12
3.123.2123
*/