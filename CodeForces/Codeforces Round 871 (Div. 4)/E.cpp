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
const int maxn=1e6+100;
const int N=1e3+100;
bool vis[N][N];
int mp[N][N];
int n,m;
int bfs(int sx,int sy)
{
	queue<pii>q;
	ll ans=0;
	q.push({sx,sy});
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		if(vis[x][y])continue;
		ans+=mp[x][y];
		vis[x][y]=1;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[xx][yy]==0)continue;
			if(vis[xx][yy])continue;
			q.push({xx,yy});
		}
	}
	return ans;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			vis[i][j]=0;
		}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j]==0&&mp[i][j]!=0)
				ans=max(ans,bfs(i,j));
	cout<<ans<<endl;
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