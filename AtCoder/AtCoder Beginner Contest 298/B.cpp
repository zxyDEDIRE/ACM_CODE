/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
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
int a[N][N];
int b[N][N];
int c[N][N];
int n;
bool check()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(a[i][j]==1&&b[i][j]==0)
				return 0;
	return 1;
}
void doit()
{

	for(int i=1,t=n;i<=n;i++,t--)
	{
		for(int j=1;j<=n;j++)
		{
			// c[j][t]=a[i][j];
			c[i][j]=a[n-j+1][i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			a[i][j]=c[i][j];
			// cout<<a[i][j]<<" ";
		}
		// cout<<endl;
	}
	// cout<<endl;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>b[i][j];
	for(int k=1;k<=4;k++)
	{
		if(check()){
			cout<<"Yes"<<endl;
			return ;
		}
		doit();
	}
	cout<<"No"<<endl;
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
1 2 3
4 5 6
7 8 9

n+1-j i


1 1 -> 3 1
1 2 -> 2 1 
1 3 -> 1 1

*/