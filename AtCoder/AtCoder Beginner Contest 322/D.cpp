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
const int N=30;
char p[N][N][N];
bool vis[N][N];
int a,b,c;
int n=4;
void f(int a,int b)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			p[b][i][j]=p[a][n-j+1][i];
		}
	}
}
/*
....
#...
#...
#...
*/
int flag=0;
void dfs(int step)
{
	if(flag)return ;
	if(step==3){
		flag=1;
		return ;
	}
	for(int x=-4;x<=4;x++)
	{
		for(int y=-4;y<=4;y++)
		{
			int ok=1;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					int _x=i+x;
					int _y=j+y;
					if(_x<1||_x>n||_y<1||_y>n)ok=0;
					if(vis[_x][_y])ok=0;
				}
			}
			if(ok)
			{
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						int _x=i+x;
						int _y=j+y;
						vis[_x][_y]=1;
					}
				}
				dfs(step+1);
				for(int i=1;i<=n;i++)
				{
					for(int j=1;j<=n;j++)
					{
						int _x=i+x;
						int _y=j+y;
						vis[_x][_y]=0;
					}
				}
			}
		}
	}
}
void solve()
{
	int cnt=0;
	for(int k=1;k<=3;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				cin>>p[k][i][j];
				if(p[k][i][j]=='#')cnt++;
			}
	if(cnt!=16){
		cout<<"No";
		return ;
	}
	for(int i=1;i+3<=9;i++)
		f(i,i+3);

	

	for(a=1;a<=9;a+=3)
	{
		for(b=2;b<=9;b+=3)
		{
			for(c=3;c<=9;c+=3)
			{
				dfs(0);
				if(flag){
					cout<<"Yes\n";
					return ;
				}
			}
		}
	}
	cout<<"No";
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
###.
.##.
..#.
.###

....
...#
..##
...#

....
#...
#...
#...

*/