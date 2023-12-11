/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define p(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={-1,0,1,0,1,-1,1,-1};
const int dy[]={0,1,0,-1,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=111;
bool vis[N][N];
int a[maxn];
int p[N][N];
int n;
void dfs(int x,int y,int step,int fl)
{
	vis[x][y]=1;
	p[x][y]=a[step];
	if(step==n*n)return ;
	int xx=x+dx[fl%4];
	int yy=y+dy[fl%4];
	if(xx<1||yy<1||xx>n||yy>n||vis[xx][yy])
	{
		fl++;
		xx=x+dx[fl%4];
		yy=y+dy[fl%4];
	}
	dfs(xx,yy,step+1,fl);
}
void solve()
{
	cin>>n;
	int l=1,r=n*n;
	for(int i=1;i<=n*n;i++)
		if(i&1)a[i]=l++;
		else a[i]=r--;

	// for(int i=1;i<=n;i++)
	// 	for(int j=1;j<=n;j++)
	// 		cin>>p[i][j];

	dfs(1,1,1,0);

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cout<<p[i][j]<<" ",vis[i][j]=0;
		cout<<endl;
	}


	// cout<<endl;
	// set<int>s;
	// for(int i=1;i<=n;i++)
	// {
	// 	for(int j=1;j<=n;j++)
	// 	{
	// 		s.insert(abs(p[i][j]-p[i][j+1]));
	// 		s.insert(abs(p[i][j]-p[i+1][j]));
	// 	}
	// }
	// // cout<<s.size()-1<<endl;
	// for(auto i:s)
	// 	cout<<i<<" ";
	// cout<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
1 3 4
9 2 7
5 8 6


1 2 3
8 9 4
7 6 5


1 2 3 4 5 6 7 8 9

1 3 4
9 2 7
5 8 6


1 9 3
2 8 5
4 7 6


1 5 4
9 6 7
2 8 3

1 8 4
9 3 6
2 7 5

1  11 6  12
16 7  9  5
2  10 8  13
15 3  14 4



1  3  5  7
16 14 12 10
2  4  6  8
15 13 11 9


1 9 2 8 3 7 4 6 5
*/ 