#include<bits/stdc++.h>
using namespace std;
const int N=100;
int mp[N][N];
int n,m;

bool f(int x,int y,int _x,int _y)
{
	int flag=mp[x][y];
	for(int i=x;i<=_x;i++)
		for(int j=y;j<=_y;j++)
			if(mp[i][j]!=mp[x][y])
				return 0;
	return 1;
}
bool check()
{
	int a=0,b=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			for(int I=i;I<=n;I++)
				for(int J=j;J<=m;J++)
					if(f(i,j,I,J))a++;
					else b++;
		}
	cout<<a<<" "<<b<<endl;
	if(a==b)
		return 1;
	return 0;
}
signed main()

{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	cout<<check()<<endl;
}
/*
5 12 
0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 1 1 1 0
0 0 0 0 0 0 0 1 1 1 1 0
*/