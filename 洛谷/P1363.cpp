/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=1600;
bitset<maxn>vis[maxn];
string mp[maxn];
int p[maxn][maxn];
int n,m,sx,sy,cnt;
void bfs(int s,int t)
{
	queue<pii>q;
	q.push({s,t});
	while(!q.empty())
	{
		auto [x,y]=q.front();q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		p[x][y]=cnt;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>n||mp[xx][yy]=='#'||vis[xx][yy])continue;
			q.push({xx,yy});
		}
	}
}
void solve()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin>>mp[i][j];
				if(mp[i][j]=='S')sx=i,sy=j;
				p[i][j]=-1;
			}
			vis[i].reset();
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(mp[i][j]!='#'&&!vis[i][j]){
					cnt++;
					bfs(i,j);
				}
			}
		}
		int flag=0;
		for(int i=1;i<=n;i++){
			if(p[i][1]==p[i][m]&&p[i][1]==p[sx][sy]){
				flag=1;
				break;
			}
		}
		for(int i=1;i<=m;i++){
			if(p[1][i]==p[n][i]&&p[1][i]==p[sx][sy]){
				flag=1;
				break;
			}
		}
		if(flag)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}
int main()
{	
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}