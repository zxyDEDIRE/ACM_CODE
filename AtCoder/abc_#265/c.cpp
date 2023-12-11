/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=600;
bool vis[maxn][maxn];
char mp[maxn][maxn];
int n,m;
void dfs(int x,int y)
{
	if(vis[x][y])
	{
		cout<<-1<<endl;
		return ; 
	}
	vis[x][y]=1;
	char ch=mp[x][y];
	int flag=0;
	if(ch=='U'&&x>1)flag=1,dfs(x-1,y);
	if(ch=='D'&&x<n)flag=1,dfs(x+1,y);
	if(ch=='R'&&y<m)flag=1,dfs(x,y+1);
	if(ch=='L'&&y>1)flag=1,dfs(x,y-1);
	if(flag==0)
		cout<<x<<" "<<y<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	dfs(1,1);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}