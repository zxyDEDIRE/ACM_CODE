#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=333;
int dis[maxn][maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;cin>>x>>y;
		dis[x][y]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]|=(dis[i][k]&dis[k][j]);
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		int num=0;
		for(int j=1;j<=n;j++)
			if(i!=j&&(dis[i][j]||dis[j][i]))num++;
		if(num==n-1)cnt++;
	}
	cout<<cnt<<endl;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}