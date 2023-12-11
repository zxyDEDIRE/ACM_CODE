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
struct node{int x,y,step;};
const int N=1000+7;
bool vis[N][N];
char mp[N][N];
int p[N][N];
int n,m;
void bfs()
{
	queue<pii>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='F')
				q.push({i,j}),p[i][j]=0,vis[i][j]=1;
			else p[i][j]=INF,vis[i][j]=0;
		}
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]=='#')continue;
			if(vis[xx][yy])continue;
			p[xx][yy]=p[x][y]+1;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
}
void _bfs()
{
	queue<node>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			vis[i][j]=0;
			if(mp[i][j]=='J')
				q.push({i,j,0}),vis[i][j]=1;
		}
	while(!q.empty())
	{
		auto [x,y,step]=q.front();q.pop();
		if(x<1||y<1||x>n||y>m){
			cout<<step<<endl;
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m){
				q.push({xx,yy,step+1});
				continue;
			}
			if(mp[xx][yy]=='#')continue;
			if(p[xx][yy]<=step+1)continue;
			if(vis[xx][yy])continue;
			vis[xx][yy]=1;
			q.push({xx,yy,step+1});
		}
	}
	cout<<"IMPOSSIBLE"<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	bfs();
	_bfs();
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=m;j++)
	// 		cout<<p[i][j]<<" ";
	// 	cout<<endl;
	// }
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}