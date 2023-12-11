#include<bits/stdc++.h>
using namespace std;
int dp[100][100][100];
int f(int x,int y,int z)
{
	
	if(x<=0||y<=0||z<=0)return 1;
	if(x>20||y>20||z>20)return  f(20,20,20);
	if(dp[x][y][z]!=0)return dp[x][y][z];
	if(x<y&&y<z)return dp[x][y][z]=f(x,y,z-1)+f(x,y-1,z-1)-f(x,y-1,z);
	return dp[x][y][z]=f(x-1,y,z)+f(x-1,y-1,z)+f(x-1,y,z-1)-f(x-1,y-1,z-1);
}
int main()
{
	while(1)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x==-1&&y==-1&&z==-1)break;
	//	cout<<"ans: ";
		cout<<f(x,y,z)<<endl;
	}
	
}
/*
0 0 0
-1 7 18
17 17 18
19 17 18
21 -21 20
-1 -1 -11
20 30 20
5 6 9
10 12 18
22 25 26
-1 -1 -1
*/