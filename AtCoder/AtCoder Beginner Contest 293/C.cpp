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
const int N=11;
int mp[N][N];
map<int,bool>vis;
int n,m,cnt;
void dfs(int x,int y)
{
	if(x==n&&y==m)
	{
		cnt++;
		return ;
	}
	if(x+1<=n&&vis[mp[x+1][y]]!=1)
	{
		vis[mp[x+1][y]]=1;
		dfs(x+1,y);
		vis[mp[x+1][y]]=0;
	}
	if(y+1<=m&&vis[mp[x][y+1]]!=1)
	{
		vis[mp[x][y+1]]=1;
		dfs(x,y+1);
		vis[mp[x][y+1]]=0;
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	vis[mp[1][1]]=1;
	dfs(1,1);
	cout<<cnt<<endl;
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