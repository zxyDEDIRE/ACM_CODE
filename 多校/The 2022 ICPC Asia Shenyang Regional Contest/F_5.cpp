#include<bits/stdc++.h>
using namespace std;
const int N=100;
int mp[N][N];
int n,m;
set<long long>s;
bool f(int x,int y,int _x,int _y)
{
	int flag=mp[x][y];
	for(int i=x;i<=_x;i++)
		for(int j=y;j<=_y;j++)
			if(mp[i][j]!=mp[x][y])
				return 0;
	return 1;
}
void ok()
{
	int a=0,b=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			for(int I=i;I<=n;I++)
				for(int J=j;J<=m;J++)
					if(f(i,j,I,J))a++;
					else b++;
		}
	int cnt_1=0,cnt_2=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mp[i][j]==1)
				cnt_1++;
	if(a==b)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				cout<<mp[i][j]<<" ";
			cout<<endl;
		}
		// long long now=0;
		// for(int i=1;i<=m;i++){
		// 	cout<<mp[(n+1)/2][i]<<" ";
		// 	if(mp[(n+1)/2][i])now+=(1ll<<(i-1));
		// }
		// s.insert(now);
		// cout<<now;
		cout<<endl;
	}
}
void dfs(int x,int y)
{
	if(x>n)
	{
		ok();
		return ;
	}
	int xx=x;
	int yy=y+1;
	if(yy>m)xx++,yy=1;
	dfs(xx,yy);
	int mid=(n+1)/2;
	// if(x!=mid)return ;
	mp[x][y]=1;
	dfs(xx,yy);
	mp[x][y]=0;
}
long long get(long long n)
{
	return n*(n+1)/2;
}
signed main()
{
	n=4;
	m=5;
	long long tp=get(n)*(get(m));
	if(tp&1)cout<<"NO"<<endl;
	else 
		dfs(1,1);
	for(auto i:s)
		cout<<i<<endl;
}
/*
8

1 1 1 0 1 1 0 0
*/