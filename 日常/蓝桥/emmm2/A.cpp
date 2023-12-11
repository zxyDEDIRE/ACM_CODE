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
const int N=1e4+10;
bool vis[N][N];
bool ok[N][N];
void dfs(int x,int y)
{
	if(x>1e4)return ;
	if(y>1e4)return ;
	if(vis[x][y])return ;
	vis[x][y]=1;
	if(x%2==0)dfs(x,y+3);
	if(x%3==0)dfs(x,y+2);
	if(y%2==0)dfs(x+3,y);
	if(y%3==0)dfs(x+2,y);
}
void init()
{
	dfs(2,3);
}
void solve()
{
	int x,y;
	cin>>x>>y;
	if(vis[x][y])cout<<"Yes\n";
	else cout<<"No\n";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	init();
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
4
7 6
2 2
12 8
1 12
*/