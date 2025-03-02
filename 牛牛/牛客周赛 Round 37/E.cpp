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
const int N=1111;
struct node{
	int x,y,op;
};
int dis[N][N][4];
char mp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	pii s,t;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='S')s={i,j};
			if(mp[i][j]=='T')t={i,j};
			for(int k=0;k<4;k++)
				dis[i][j][k]=INF;
		}
	queue<node>q;
	for(int i=0;i<4;i++)
	{
		q.push({s.first,s.second,i});
		dis[s.first][s.second][i]=0;
	}
	while(!q.empty())
	{
		auto [x,y,op]=q.front();q.pop();
		if(x==t.first&&y==t.second)break;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]=='#')continue;
			if(mp[x][y]=='.'&&i!=op)continue;
			if(dis[xx][yy][i]>dis[x][y][op]+1)
			{
				dis[xx][yy][i]=dis[x][y][op]+1;
				q.push({xx,yy,i});
			}
		}
	}
	int mi=INF;
	for(int i=0;i<4;i++)
		mi=min(mi,dis[t.first][t.second][i]);
	if(mi==INF)cout<<-1<<endl;
	else cout<<mi<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}