#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2222;
int dis[N][N];
int n,m,num;
void dfs(int x,int y)
{
	if(x>n)
	{
		int flag=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(i>1&&dis[i][j]>dis[i-1][j])flag=0;
				if(j>1&&dis[i][j]>dis[i][j-1])flag=0;
				if(i>1&&dis[i][j]==1&&dis[i-1][j]==2)flag=0;
				if(j>1&&dis[i][j]==1&&dis[i][j-1]==2)flag=0;
			}
		}
		num+=flag;
		if(flag){
			// for(int i=1;i<=n;i++)
			// {
			// 	for(int j=1;j<=m;j++)
			// 		cout<<dis[i][j]<<" ";
			// 	cout<<endl;
			// }
		}
		return ;
	}
	int xx=x;
	int yy=y+1;
	if(yy>m)xx++,yy=1;

	for(int i=3;i>=0;i--)
	{
		int flag=1;
		dis[x][y]=i;
		if(x>1&&dis[x][y]>dis[x-1][y])flag=0;
		if(y>1&&dis[x][y]>dis[x][y-1])flag=0;
		if(x>1&&dis[x][y]==1&&dis[x-1][y]==2)flag=0;
		if(y>1&&dis[x][y]==1&&dis[x][y-1]==2)flag=0;
		if(flag)
			dfs(xx,yy);
	}
}
const int mod=1e9+7;
long long ksm(long long a,long long b)
{
	int res=1;
	a%=mod;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}
int solve()
{
	num=0;
	dis[1][1]=3;
	dfs(1,2);
	// cout<<num<<endl;
	return num;
	// cout<<(1ll+ksm(2,m+n-1)+ksm(4,n+m-2))%mod<<'\n';
}
signed main()
{
	for(int i=1;i<=8;i++)
	{
		for(int j=2;j<=8;j++){
			n=i,m=j;
			int t=solve();
			printf("(%d,%d:=%10d %5d ) ",i,j,t,(int)sqrt(t));
		}
		cout<<endl;
	}
}
/*

2  3  4  5   6   7  8
5  9 14 20  27  35  44
9 81 
*/