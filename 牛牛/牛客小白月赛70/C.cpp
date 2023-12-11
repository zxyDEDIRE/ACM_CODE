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
const int N=1000+100;
bitset<N>vis[N];

char mp[N][N];
int sx,sy;
int n,m,ans;
void dfs(int x,int y)
{
	if(vis[x][y])return ;
	vis[x][y]=1;

	// int now=0;
	// if(mp[x][y]=='!')now++;
	// for(int i=x+1;i<=n;i++)
	// {
	// 	if(mp[i][y]=='#')break;
	// 	if(mp[i][y]=='!')now++;
	// }
	// for(int i=x-1;i>=1;i--)
	// {
	// 	if(mp[i][y]=='#')break;
	// 	if(mp[i][y]=='!')now++;
	// }
	// for(int j=y+1;j<=m;j++)
	// {
	// 	if(mp[x][j]=='#')break;
	// 	if(mp[x][j]=='!')now++;
	// }
	// for(int j=y-1;j>=1;j--)
	// {
	// 	if(mp[x][j]=='#')break;
	// 	if(mp[x][j]=='!')now++;
	// }
	// ans=max(ans,now);
	if(mp[x][y]=='!')ans++;

	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]=='#')continue;
		dfs(xx,yy);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='@'){
				sx=i;
				sy=j;
			}
		}

	dfs(sx,sy);
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}