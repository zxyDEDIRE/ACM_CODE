/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define endl "\n"
const int dx[]={0,0,0,-1};
const int dy[]={0,-1,1,0};
const int maxn=30;
int mp[maxn][maxn];
int vis[maxn][maxn];
int n,m;
int doit()
{
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int cnt=mp[i][j];
			for(int k=0;k<4;k++)
			{
				int x=i+dx[k];
				int y=j+dy[k];
				cnt+=vis[x][y];
			}
			if(cnt&1)
				vis[i+1][j]=1;
		}
	}
	//cout<<"Yes"<<endl;
	for(int j=1,i=n;j<=m;j++)
	{
		int cnt=mp[i][j];
		for(int k=0;k<4;k++)
		{
			int x=i+dx[k];
			int y=j+dy[k];
			cnt+=vis[x][y];
		}
		if(cnt&1)return -1;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(vis[i][j])cnt++;
		}
	}
	return cnt;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>mp[i][j];
	int mi=1e9;
	string ans;
	//for(int i=(1<<m)-1;i>=0;i--)
	for(int i=0;i<(1<<m);i++)
	{
		memset(vis,0,sizeof(vis));
		for(int j=0;j<m;j++)
			if(i&(1<<j))vis[1][j+1]=1;
		int fl=doit();
		if(fl==-1)continue;
		//cout<<fl<<endl;
		if(fl<=mi)
		{
			string str;
			for(int ii=1;ii<=n;ii++)
				for(int j=1;j<=m;j++){
					if(vis[ii][j])str+='1';
					else str+='0';
				}
			if(fl<mi)ans=str;
			else if(fl==mi)ans=min(ans,str);
			mi=fl;
		}
	}
	//cout<<mi<<endl;
	if(mi==1e9)cout<<"IMPOSSIBLE"<<endl;
	else
	{
		int k=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++)
				cout<<ans[k]<<" ",k++;
			cout<<endl;
		}
	}
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
		solve();
	return 0;
}