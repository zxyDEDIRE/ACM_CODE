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
const int N=2e3+10;
struct node{
	int x,y,d;
};
bool vis[N][N];
char mp[N][N];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	map<int,set<char>>s;
	queue<node>q;
	q.push({1,1,1});
	while(!q.empty())
	{
		auto [x,y,d]=q.front();q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		s[d].insert(mp[x][y]);
		if(s[d].size()>1){
			cout<<d-1<<endl;
			return ;
		}
		if(x+1<=n)
			q.push({x+1,y,d+1});
		if(y+1<=m)
			q.push({x,y+1,d+1});
	}
	cout<<n+m-1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}