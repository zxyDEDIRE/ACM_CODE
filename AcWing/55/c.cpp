/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<bits/stdc++.h>
#define int long long
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=2020;
string mp[maxn];
bool vis[maxn][maxn];
int dis[maxn][maxn];
int ga[maxn][maxn];
int gb[maxn][maxn];
int n,m,r,c,x,y;
void solve()
{
	cin>>n>>m>>r>>c>>x>>y;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];
		mp[i]=" "+mp[i];
	}
	ga[r][c]=x;
	gb[r][c]=y;
	vis[r][c]=1;
	int ans=0;
	deque<pii>q;
	q.push_back({r,c});
	while(!q.empty())
	{
		ans++;
		auto [x,y]=q.front();q.pop_front();
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m||mp[xx][yy]=='*'||vis[xx][yy])continue;
			vis[xx][yy]=1;
			if(i>=2)
			{
				ga[xx][yy]=ga[x][y];
				gb[xx][yy]=gb[x][y];
				q.push_front({xx,yy});
			}
			else if(i==0&&gb[x][y])//you
			{
				ga[xx][yy]=ga[x][y];
				gb[xx][yy]=gb[x][y]-1;
				q.push_back({xx,yy});
			}
			else if(i==1&&ga[x][y])
			{
				ga[xx][yy]=ga[x][y]-1;
				gb[xx][yy]=gb[x][y];
				q.push_back({xx,yy});
			}
		}
	}
	cout<<ans<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);

        solve();
    return 0;
}