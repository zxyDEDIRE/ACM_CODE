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
const int N=400;
struct node{
	int x,y,fl;
};
bool vis[N][N];
bool ok[N][N][4];
char mp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	queue<node>q;
	for(int i=0;i<4;i++)
		q.push({2,2,i});
	vis[2][2]=1;
	while(!q.empty())
	{
		auto [x,y,fl]=q.front();q.pop();
		if(ok[x][y][fl])continue;
		ok[x][y][fl]=1;
		while(mp[x+dx[fl]][y+dy[fl]]!='#')
		{
			x+=dx[fl];
			y+=dy[fl];
			vis[x][y]=1;
		}
		for(int i=0;i<4;i++)
			q.push({x,y,i});
	}
	int ans=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(vis[i][j])ans++;
	cout<<ans<<endl;
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
/*
5 6
######
#..#.#
##...#
#....#
######

5 6
######
#^^#^#
##^.^#
#^^^^#
######
*/