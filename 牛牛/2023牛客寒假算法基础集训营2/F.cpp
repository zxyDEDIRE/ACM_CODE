/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,1};
const int dy[]={1,0};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=6e5+100;
pii p[maxn];
bool vis[maxn][4];
int mp[maxn][4];
int ok[maxn][4];
int n,k;
bool dfs(int x,int y)
{
	if(x==n&&y==3){
		ok[x][y]=1;
		return 1;
	}
	if(ok[x][y]==1)return 1;
	if(ok[x][y]==-1)return 0;
	int flag=0;
	for(int i=0;i<2;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(vis[xx][yy])continue;
		if(xx<1||yy<1||xx>n||yy>3)continue;
		if(ok[xx][yy]==-1)continue;
		if(ok[xx][yy]){flag=1;continue;}
		flag|=dfs(xx,yy);
	}
	if(flag)ok[x][y]=1;
	else ok[x][y]=-1;

	return flag;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		vis[i][3]=vis[i][1]=vis[i][2]=0;
		ok[i][3]=ok[i][1]=ok[i][2]=0;
	}
	for(int i=1;i<=k;i++){
		int x,y;
		cin>>x>>y;
		if(vis[x][y])vis[x][y]=0;
		else vis[x][y]=1;
	}
	dfs(1,1);
	ok[1][1]=0;
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=3;j++)
			if(ok[i][j]>0)
				ans+=ok[i][j];
	cout<<ans<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}