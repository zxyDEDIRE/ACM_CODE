/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define nullptr 0
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e3+100;
struct node{
	int x,y,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
bool vis[maxn][maxn];
char mp[maxn][maxn];
int dis[maxn][maxn];
int n;
void bfs()
{
	priority_queue<node>q;
	q.push(node{0,0,0});
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.x;
		int y=now.y;
		int t=now.dis;
		if(vis[x][y])continue;
		vis[x][y]=1;
		dis[x][y]=t;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(mp[xx][yy]=='*')continue;
			if(xx<0||yy<0||xx>=n||yy>=n)continue;
			q.push(node{xx,yy,t+1});
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>mp[i][j],dis[i][j]=INF;
	bfs();
	int x,y,t;
	while(cin>>x>>y>>t&&x!=-1)
	{
		if(dis[x][y]==INF||t<dis[x][y])cout<<-1<<endl;
		else cout<<1<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}