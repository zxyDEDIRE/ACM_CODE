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
int cnt[111][111];
int mp[111][111];
int vis[111][111];
int n,m,flag;
void dfs(int x,int y)
{
	cout<<x<<" "<<y<<endl;
	if(flag)return ;
	if(x>n)
	{
		flag=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(cnt[i][j]+mp[i][j]%2==1)
					flag=0;
		if(flag)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
					cout<<vis[i][j]<<" ";
				cout<<endl;
			}
			cout<<"YES"<<endl;
		}
		return ;
	}
	int xx=x;
	int yy=y+1;
	if(yy>m)xx++,yy=1;
	vis[xx][yy]=1;
	dfs(xx,yy);

	for(int k=0;k<4;k++)
	{
		int X=x+dx[k];
		int Y=y+dy[k];
		cnt[X][Y]++;
	}
	vis[xx][yy]=2;
	dfs(xx,yy);
	cnt[x][y]++;
	vis[xx][yy]=3;
	dfs(xx,yy);
	for(int k=0;k<4;k++)
	{
		int X=x+dx[k];
		int Y=y+dy[k];
		cnt[X][Y]--;
	}
	cnt[x][y]--;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cin>>
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
/*
2 3
WBW
BBW

0 1 1
2 1 3

*/