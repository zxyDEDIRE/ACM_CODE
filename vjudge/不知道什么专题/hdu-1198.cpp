/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int INF=0x3f3f3f3f;
const int maxn=55;
const int N=1e5;
char mp[maxn][maxn];
bool vis[2555][4];
int p[N];
int n,m;
int find(int r){
	return p[r]=p[r]==r?p[r]:find(p[r]);
}
int f(int x,int y)
{
	return (x-1)*m+y;
}
void un(int ax,int ay,int bx,int by)
{
	int x=(ax-1)*m+ay;
	int y=(bx-1)*m+by;
	int fa=find(x);
	int fb=find(y);
	if(fa!=fb){
		p[fa]=fb;
	}
}
void solve()
{
	while(cin>>n>>m&&n!=-1)
	{
		memset(vis,0,sizeof(vis));

		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[i][j];
				char ch=mp[i][j];
				if((ch=='A'||ch=='B'||ch=='E'||ch=='G'||ch=='H'||ch=='J'||ch=='K'))vis[f(i,j)][0]=1;
				if((ch=='A'||ch=='C'||ch=='F'||ch=='G'||ch=='H'||ch=='I'||ch=='K'))vis[f(i,j)][1]=1;
				if((ch=='C'||ch=='D'||ch=='E'||ch=='H'||ch=='I'||ch=='J'||ch=='K'))vis[f(i,j)][2]=1;
				if((ch=='B'||ch=='D'||ch=='F'||ch=='G'||ch=='I'||ch=='J'||ch=='K'))vis[f(i,j)][3]=1;
			}
		}

		for(int i=1;i<=n*m;i++)
			p[i]=i;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(vis[f(i,j)][0]&&vis[f(i-1,j)][2]&&i>1)un(i,j,i-1,j);
				if(vis[f(i,j)][1]&&vis[f(i,j-1)][3]&&j>1)un(i,j,i,j-1);
				if(vis[f(i,j)][2]&&vis[f(i+1,j)][0]&&i<n)un(i,j,i+1,j);
				if(vis[f(i,j)][3]&&vis[f(i,j+1)][1]&&j<m)un(i,j,i,j+1);
			}
		}
		int cnt=0;
		for(int i=1;i<=n*m;i++)
		{
			if(p[i]==i)
				cnt++;
		}
		cout<<cnt<<endl;
	}
}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
1 2
FF
*/