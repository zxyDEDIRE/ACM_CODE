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
const int N=2222;
char mp[N][N];
bool vis[N][N];
int dis[N][N];
pii s,t;
int n,m;
void f(int x,int y,int fl){
	while(1)
	{
		vis[x][y]=1;
		x+=dx[fl];
		y+=dy[fl];
		if(mp[x][y]!='.')break;
		if(x<1||y<1||x>n||y>m)break;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='S')s={i,j};
			if(mp[i][j]=='G')t={i,j};
			// if(mp[i][j]=='>')f(i,j,0);
			// if(mp[i][j]=='<')f(i,j,1);
			// if(mp[i][j]=='v')f(i,j,2);
			// if(mp[i][j]=='^')f(i,j,3);
			dis[i][j]=INF;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(mp[i][j]=='>')f(i,j,0);
			if(mp[i][j]=='<')f(i,j,1);
			if(mp[i][j]=='v')f(i,j,2);
			if(mp[i][j]=='^')f(i,j,3);
		}
	queue<pii>q;
	q.push(s);
	dis[s.first][s.second]=0;
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>n)continue;
			if(vis[xx][yy]||mp[xx][yy]=='#')continue;
			if(dis[xx][yy]>dis[x][y]+1)
			{
				dis[xx][yy]=dis[x][y]+1;
				q.push({xx,yy});
			}
		}
	}
	int ans=dis[t.first][t.second];
	if(ans==INF)cout<<-1<<endl;
	else cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}