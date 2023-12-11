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
const int N=222;
bitset<N>vis[N];
char mp[N][N];
int n,m;
void bfs(int sx,int sy,vector<vector<int>> &dis)
{
	for(int i=1;i<=n;i++)
		vis[i].reset();
	queue<array<int,2>>q;
	q.push({sx,sy});
	vis[sx][sy]=1;
	dis[sx][sy]=0;
	while(!q.empty())
	{
		array<int,2>now=q.front();q.pop();
		int x=now[0];
		int y=now[1];
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]=='#')continue;
			if(vis[xx][yy])continue;
			dis[xx][yy]=dis[x][y]+11;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 		cout<<dis[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<endl;
}
void solve()
{
	vector<vector<int>>dis_a(n+1,vector<int>(m+1));
	vector<vector<int>>dis_b(n+1,vector<int>(m+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j],dis_a[i][j]=dis_b[i][j]=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='Y')bfs(i,j,dis_a);
			if(mp[i][j]=='M')bfs(i,j,dis_b);
		}
	int mi=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='@')
				mi=min(mi,dis_a[i][j]+dis_b[i][j]);
	cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}