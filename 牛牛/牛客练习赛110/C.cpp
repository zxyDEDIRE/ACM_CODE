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
const int dx[]={-1,-1,1,1};
const int dy[]={1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+10;
bool vis[5000][5000];
int sx,sy;
int n;
void f_1(int m,int op)
{
	m/=2;
	for(int k=0;k<4;k++)
	{
		int x=sx+m*dx[k];
		int y=sy+m*dy[k];
		for(int i=1;i<=m;i++)
		{
			vis[x+i*dx[(k+1)%4]][y+i*dy[(k+1)%4]]=1;
		}
	}
}
void f_2(int m,int op)
{
	m/=2;
	for(int k=0;k<4;k++)
	{
		int x=sx+m*dx[k];
		int y=sy+m*dy[k];
		for(int i=1;i<=m;i++)
		{
			vis[x+i*dx[(k+3)%4]][y+i*dy[(k+3)%4]]=1;
		}
	}
}
void solve()
{
	cin>>n;
	vector<int>v;
	v.push_back(4);
	for(int i=1;i<n;i++)
		v.push_back(v.back()*2);
	sx=v.back()+1;
	sy=v.back()+1;
	int m=v.back();
	for(int i=1;i<=m*2+1;i++)
	{
		vis[m+1][i]=1;
		vis[i][m+1]=1;
	}
	for(int i=1;i<=m/2;i++)
	{
		vis[sx+i][sy+i]=1;
		vis[sx-i][sy-i]=1;
		vis[sx-i][sy+i]=1;
		vis[sx+i][sy-i]=1;
	}
	int fl=0;
	for(auto i:v)
	{
		if(!fl)f_1(i,fl);
		else f_2(i,fl);
		fl^=1;
	}
	for(int i=1;i<=m*2+1;i++)
	{
		for(int j=1;j<=m*2+1;j++)
			if(vis[i][j])cout<<"*";
			else cout<<" ";
		cout<<endl;
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
