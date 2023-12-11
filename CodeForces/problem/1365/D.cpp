/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=100;
bool vis[maxn][maxn];
char mp[maxn][maxn];
int n,m;
int flag=0;
void dfs(int x,int y)
{
	if(flag)return ;
	if(x==n&&y==m){
		flag=1;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]=='#')continue;
		if(vis[xx][yy])continue;
		vis[xx][yy]=1;
		dfs(xx,yy);
		vis[xx][yy]=0;
	}
}
void solve()
{
	cin>>n>>m;
	int tot=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='G')
				tot++;
			vis[i][j]=0;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]=='B'){
				for(int k=0;k<4;k++)
					if(mp[i+dx[k]][j+dy[k]]!='B')
						mp[i+dx[k]][j+dy[k]]='#';
			}
	int cnt=0;
	queue<pii>q;
	if(mp[n][m]!='#')
		q.push({n,m});
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		if(mp[x][y]=='G')cnt++;

		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(vis[xx][yy])continue;
			if(mp[xx][yy]=='#')continue;
			vis[xx][yy]=1;
			q.push({xx,yy});
		}
	}
	if(cnt==tot)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
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