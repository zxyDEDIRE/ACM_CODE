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
int n,m,k;
struct node{
	bool vis[7][7];
	int cnt=0;
	node(){
		memset(vis,0,sizeof(vis));
	}
	bool operator<(const node&a)const{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(a.vis[i][j]!=vis[i][j])
					return a.vis[i][j]>vis[i][j];
			}
		return 1;
	}
};

map<node,bool>mp;
int ans;
bool ok(int x,int y){
	if(x<1||y<1||x>n||y>m)return 0;
	return 1;
}
void dfs(node A)
{
	if(mp[A])return ;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++)
	// 		cout<<A.vis[i][j]<<" ";
	// 	cout<<endl;
	// }
	// cout<<A.cnt<<endl;
	ans=min(ans,A.cnt);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(!A.vis[i][j])continue;
			for(int k=0;k<4;k++)
			{
				int x = i+dx[k];
				int y = j+dy[k];
				int _x = x + dx[k];
				int _y = y + dy[k];
				if(!ok(_x,_y))continue;
				if(!A.vis[x][y]||A.vis[_x][_y])continue;
				node now=A; 
				now.vis[x][y]=now.vis[i][j]=0;
				now.vis[_x][_y]=1;
				now.cnt--;
				dfs(now);
			}
		}
	}
}
void solve()
{
	cin>>n>>m>>k;
	// n=5;
	// m=5;
	// k=6;
	ans=k;
	node a;
	mp.clear();

	// for(int i=1;i<=6;i++)
	// {
	// 	while(1)
	// 	{
	// 		int x=rand()%5+1;
	// 		int y=rand()%5+1;
	// 		if(!a.vis[x][y])
	// 		{
	// 			a.vis[x][y]=1;
	// 			break;
	// 		}
	// 	}
	// }
	for(int i=1;i<=k;i++)
	{
		int x,y;cin>>x>>y;
		a.vis[x][y]=1;
	}

	a.cnt=k;
	dfs(a);
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1
6 6 
*/