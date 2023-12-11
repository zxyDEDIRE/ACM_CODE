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
const int N=900;
struct node{
	int x,y,w;
	node ():w(0){}
	node (int a,int b,int c):x(a),y(b),w(c){}
};
bool vis[N][N];
int dis_b[N][N];
int dis_a[N][N];
char mp[N][N];
vector<pii>v;
int n,m;
bool ok(int x,int y,int step)
{
	for(int i=0;i<v.size();i++)
	{
		int a=v[i].first;
		int b=v[i].second;
		if(abs(a-x)+abs(b-y)<=step*2){
			return 0;
		}
	}
	return 1;
}
void bfs_1(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push(node(sx,sy,0));
	vis[sx][sy]=1;
	while(!q.empty())
	{
		node now=q.front();q.pop();
		int x=now.x;
		int y=now.y;
		int step=now.w;
		dis_a[x][y]=(step+2)/3;
		if(!ok(x,y,dis_a[x][y]+1))continue;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]=='X')continue;
			if(vis[xx][yy])continue;
			vis[xx][yy]=1;
			q.push(node(xx,yy,step+1));
		}
	}
}
void bfs_2(int sx,int sy)
{
	memset(vis,0,sizeof(vis));
	queue<node>q;
	q.push(node(sx,sy,0));
	vis[sx][sy]=1;
	while(!q.empty())
	{
		node now=q.front();q.pop();
		int x=now.x;
		int y=now.y;
		int step=now.w;
		dis_b[x][y]=step;
		if(!ok(x,y,dis_b[x][y]+1))continue;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]=='X')continue;
			if(vis[xx][yy])continue;
			vis[xx][yy]=1;
			q.push(node(xx,yy,step+1));
		}
	}
}
void solve()
{
	cin>>n>>m;
	v.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='Z')
				v.push_back({i,j});
			dis_a[i][j]=dis_b[i][j]=INF;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='M')bfs_1(i,j);
			else if(mp[i][j]=='G')bfs_2(i,j);
	int mi=INF;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			// if(ok(i,j,max(dis_a[i][j],dis_b[i][j])))
			mi=min(mi,max(dis_a[i][j],dis_b[i][j]));
		}
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
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
5 6
XXXXXX
XZ..ZX
zzzzzX
MzG.z.
mmg...
*/