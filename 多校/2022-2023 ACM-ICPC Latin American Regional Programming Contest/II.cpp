/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
const int N=111;
struct node{
	int x,y,val;
	bool operator<(const node&a)const{
		return a.val<val;
	}
};
bitset<N>vis[N];
bool ok[maxn];
int mp[N][N];
int n,m;
int bfs(int sx,int sy)
{
	for(int i=1;i<=n;i++)
		vis[i].reset();
	priority_queue<node>q;
	q.push({sx,sy,mp[sx][sy]});
	int cnt=0,ma=0;
	while(!q.empty())
	{
		auto [x,y,val]=q.top();q.pop();
		ok[val]=1;
		if(val<=ma)continue;
		vis[x][y]=1;
		ma=val;
		cnt++;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||yy<1||xx>n||yy>m||vis[xx][yy]||mp[xx][yy]<=ma)continue;
			q.push({xx,yy,mp[xx][yy]});
		}
	}
	return cnt;
}
void solve()
{
	map<int,pii>Map;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			Map[mp[i][j]]={i,j};
		}
	int ma=0;
	for(int i=1;i<=n*m;i++)
	{
		if(ok[i])continue;
		auto [x,y]=Map[i];
		ma=max(ma,bfs(x,y));
	}
	cout<<ma<<endl;
}
signed main(){
	// freopen("C:\\Users\\tob\\Desktop\\in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
	fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
4 1 3
8 5 9
7 2 6
*/