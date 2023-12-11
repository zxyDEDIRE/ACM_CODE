#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=111;
struct node{
	int x,y,fl,step;
	bool operator<(const node&a)const{
		return a.step<step;
	}
};
bool vis[maxn][maxn][4][4];
string mp[maxn];
int n,sx,sy,tx,ty;
int bfs()
{
	priority_queue<node>q;
	for(int i=0;i<4;i++)
	{
		int xx=sx+dx[i];
		int yy=sy+dy[i];
		if(mp[xx][yy]=='x')continue;
		if(xx<1||yy<1||xx>n||yy>n)continue;
		q.push({xx,yy,i,0});
	}
	while(!q.empty())
	{
		auto [x,y,fl,step]=q.top();q.pop();
		if(x==tx&&y==ty)return step;
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(mp[xx][yy]=='x')continue;
			if(xx<1||yy<1||xx>n||yy>n)continue;
			if(vis[xx][yy][fl][i])continue;
			vis[xx][yy][fl][i]=1;
			int t=0;
			if(fl==i)t=0;
			else t=1;
			q.push({xx,yy,i,step+t});
		}
	}
	return -1;
}
int main()
{
	cin>>n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i];mp[i]=" "+mp[i];
		for(int j=1;j<=n;j++){
			if(mp[i][j]=='A')sx=i,sy=j;
			if(mp[i][j]=='B')tx=i,ty=j;
		}
	}
	cout<<bfs()<<endl;
}
/*
4
A . . B
. . . .
. . . .
. . . .
*/