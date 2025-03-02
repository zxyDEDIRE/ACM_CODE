#include<bits/stdc++.h>
#define pi(x,y) x*(n+1)+y
using namespace std;
const int maxn=100;
vector<int>v[1000000];
int mp[maxn][maxn];
int in[1000000];
int n,m,ans;
void dfs(int x,int y)
{
	in[pi(x,y)]--;
	if(!in[pi(x,y)])mp[x][y]=0;
	int t=pi(x,y);
	for(int i=0;i<v[t].size();i++)
	{
		int tt=v[t][i];
		int xx=tt/(n+1);
		int yy=tt%(n+1);
		if(!mp[xx][yy])continue;
		dfs(xx,yy);
		break;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%1d",&mp[i][j]);
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(mp[i][j])
			{
				if(mp[i][j+1])v[i*(n+1)+j].push_back(((i)*(n+1)+j+1)),in[i*(n+1)+j+1]++;
				if(mp[i+1][j])v[i*(n+1)+j].push_back(((i+1)*(n+1)+j)),in[(i+1)*(n+1)+j]++;
				
			}
		}
	}
	for(int k=1,l,r;k<=n+m;k++)
	{
		for(int i=1;i<k;i++)
		{
			l=i,r=k-l;
			if(l>n||r>m)continue;
			if(mp[l][r]){
				ans++;
				dfs(l,r);
				cout<<l<<" "<<r<<endl;
			}
		}
	}
	cout<<ans-1<<endl;
}
/*
5 5
00100
11111
00100
11111
00100

5 5
00000
00011
10001
11111
01101

*/
