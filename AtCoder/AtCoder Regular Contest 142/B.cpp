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
const int N=100;
int t[N][N];
bool vis[maxn];
int p[N][N];
int n;
bool check()
{
	for(int x=1;x<=n;x++)
	{
		for(int y=1;y<=n;y++)
		{
			int a=0,b=0;
			for(int k=0;k<8;k++)
			{
				int xx=x+dx[k];
				int yy=y+dy[k];
				if(xx<1||xx>n||yy<1||yy>n)continue;
				if(p[xx][yy]>p[x][y])a++;
				else if(p[xx][yy]<p[x][y])b++;
			}
			if(a==b){
				cout<<x<<" "<<y<<endl;
				return 0;
			}
		}
	}
	return 1;
}
int ans=0;
void dfs(int x,int y)
{
	if(x>n)
	{
		if(check())
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++){
					// t[i][j]=p[i][j];
					cout<<p[i][j]<<" ";
				}
				cout<<endl;
			}
			cout<<endl;
			ans++;
			if(ans==5)
				exit(0);
		}
		return ;
	}
	for(int i=1;i<=n*n;i++)
	{
		if(vis[i])continue;
		vis[i]=1;
		p[x][y]=i;
		if(y==n)
			dfs(x+1,1);
		else dfs(x,y+1);
		vis[i]=0;
	}
}
void solve()
{
	// cin>>n;
	// dfs(1,1);
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=n;j++)
	// 		cout<<t[i][j]<<" ";
	// 	cout<<endl;
	// }
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cin>>p[i][j];
			// cout<<(i-1)*n+j<<" ";
		}
		// cout<<endl;
	}
	cout<<check()<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1  2  3  4  5
6  7  8  9  10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25

1  2  3  4  5
6  8  9  7  10
11 13 14 12 15
16 18 19 17 20
21 22 23 24 25

1  2  3  4
5  6  7  8
9  10 11 12
13 14 15 16

1 2 3 4
5 7 6 8
9 11 10 12
13 14 15 16

1  2  3  4  5  6
7  9  8  11 10 12
13 15 14 17 16 18
19 21 20 23 22 24
25 27 26 29 28 30
31 32 33 34 35 36
*/