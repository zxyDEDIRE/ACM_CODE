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
const int dx[]={0,0,1,-1,0,0};
const int dy[]={1,-1,0,0,0,0};
const int dz[]={0,0,0,0,1,-1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=111;
struct node{int x,y,z;};
bool vis[maxn][maxn][maxn];
char mp[maxn][maxn][maxn];
int h,n,m,x,y,ans;
void solve()
{
	cin>>h>>n>>m;
	for(int k=1;k<=h;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				cin>>mp[k][i][j];
	cin>>x>>y;
	queue<node>q;
	q.push({1,x,y});
	while(!q.empty())
	{
		auto [z,x,y]=q.front();q.pop();
		if(vis[z][x][y])continue;
		vis[z][x][y]=1;
		// cout<<z<<" "<<x<<" "<<y<<endl;
		ans++;
		for(int i=0;i<6;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			int zz=z+dz[i];
			if(xx<1||xx>n||yy<1||yy>m||zz<1||zz>h)continue;
			if(vis[zz][xx][yy])continue;
			if(mp[zz][xx][yy]=='#')continue;
			q.push({zz,xx,yy});
		}
	}
	cout<<ans<<endl;
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