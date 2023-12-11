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
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=111;
char mp[N][N];
int n,m;
void f(int x,int y,int k)
{
	string str="";
	for(int i=0;i<=4;i++)
	{
		int xx=x+i*dx[k];
		int yy=y+i*dy[k];
		if(xx<1||xx>n||yy<1||yy>m)return ;
		str=str+mp[xx][yy];
	}
	if(str=="snuke")
	{
		for(int i=0;i<=4;i++)
		{
			int xx=x+i*dx[k];
			int yy=y+i*dy[k];
			cout<<xx<<" "<<yy<<endl;
		}
		exit(0);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			for(int k=0;k<8;k++)
				f(i,j,k);
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