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
const int maxn=1e6+100;
const int N=55;
bool vis[N][N];
bool ok[N][N];
char ch[N][N];
int dis[N][N];
int n,m;
void dfs(int x,int y,int w)
{
	dis[x][y]=w;
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(ch[xx][yy]!=ch[x][y])continue;
		if(vis[xx][yy])
		{
			if(w-dis[xx][yy]>=3){
				cout<<"Yes"<<endl;
				exit(0);
			}
		}
		else
		{
			vis[xx][yy]=1;
			dfs(xx,yy,w+1);
			vis[xx][yy]=0;
		}
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>ch[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(ch[i][j]==ch[i-1][j]&&ok[i-1][j])continue;
			if(ch[i][j]==ch[i][j-1]&&ok[i][j-1])continue;
			vis[i][j]=1;
			dfs(i,j,0);
			vis[i][j]=0;
			ok[i][j]=1;
		}
	cout<<"No"<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	return 0;
}
/*
*/