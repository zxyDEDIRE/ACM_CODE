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
struct node{
	int x,y,k,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
bool vis[N][N][2];
int dis[N][N][2];
char mp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<=1;k++)
				dis[i][j][k]=INF;
	priority_queue<node>q;
	q.push({1,1,0,0});
	dis[1][1][0]=0;
	while(!q.empty())
	{
		auto [x,y,k,DIS]=q.top();q.pop();
		if(x==n&&y==m){
			cout<<DIS<<endl;
			return ;
		}
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m)continue;
			if(mp[x][y]!=mp[xx][yy])
			{
				if(k==0)
				{
					if(dis[xx][yy][0]>dis[x][y][0]+1){
						dis[xx][yy][0]=dis[x][y][0]+1;
						q.push({xx,yy,0,dis[xx][yy][0]});
					}
				}
				else
				{
					if(dis[xx][yy][1]>dis[x][y][1]+2){
						dis[xx][yy][1]=dis[x][y][1]+2;
						q.push({xx,yy,1,dis[xx][yy][1]});
					}
				}
			}
			else
			{
				if(k==0)
				{
					if(dis[xx][yy][1]>dis[x][y][0]+2){
						dis[xx][yy][1]=dis[x][y][0]+2;
						q.push({xx,yy,1,dis[xx][yy][1]});
					}
				}
				else
				{
					if(dis[xx][yy][0]>dis[x][y][1]+1){
						dis[xx][yy][0]=dis[x][y][1]+1;
						q.push({xx,yy,0,dis[xx][yy][0]});
					}
				}
			}
		}
	}

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}