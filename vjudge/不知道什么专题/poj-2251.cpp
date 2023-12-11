#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;
const int maxn=200;
const int dx[]={1,-1,0,0,0,0};
const int dy[]={0,0,1,-1,0,0};
const int dz[]={0,0,0,0,1,-1};
char mp[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];
int s[10],t[10];
int h,n,m;
struct node{int x,y,z,t;};
bool check(int x,int y,int z)
{
	if(mp[x][y][z]=='#')return 0;
	if(vis[x][y][z]==1)return 0;
	if(x<1||y<1||z<1||x>n||y>m||z>h)return 0;
	return 1;
}
int bfs()
{
	vis[s[1]][s[2]][s[3]]=1;
	queue<node>q;
	node x;
	x.x=s[1],x.y=s[2],x.z=s[3],x.t=0;
	q.push(x);
	while(!q.empty())
	{
		node now=q.front();q.pop();
		if(now.x==t[1]&&now.y==t[2]&&now.z==t[3])return now.t;
		for(int i=0;i<6;i++)
		{
			int xx=now.x+dx[i];
			int yy=now.y+dy[i];
			int zz=now.z+dz[i];
			if(check(xx,yy,zz))
			{
				vis[xx][yy][zz]=1;
				node it;
				it.x=xx;it.y=yy;it.z=zz;it.t=now.t+1;
				q.push(it);
			}
		}
	}
	return -1;
}
int main()
{
	while(cin>>h>>n>>m&&m)
	{
		memset(vis,0,sizeof(vis));
		for(int k=1;k<=h;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++){
					cin>>mp[i][j][k];
					if(mp[i][j][k]=='S')s[1]=i,s[2]=j,s[3]=k;
					if(mp[i][j][k]=='E')t[1]=i,t[2]=j,t[3]=k;
				}
		int k=bfs();
		if(k==-1)cout<<"Trapped!"<<endl;
		else cout<<"Escaped in "<<k<<" minute(s)."<<endl;
	}
	
}