#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int dx[]={-2,-1,1,2,-2,-1,1,2};
const int dy[]={1,2,2,1,-1,-2,-2,-1};
const int ddx[]={-1,0,0,1,-1,0,0,1};
const int ddy[]={0,1,1,0,0,-1,-1,0};
const int maxn=500;
const int mod=1e9+7;
int vis[maxn][maxn];
int n,m,k,a,b,c,d;
struct node{
	int x,y,step;
	node(int a,int b,int c){
		x=a,y=b,step=c;
	}
	bool operator <(const node&a)const{return a.step<step;}
};
void bfsa()
{
	priority_queue<node>q;
	q.push(node(a,b,0));
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.x;
		int y=now.y;
		if(x==c&&y==d)
		{
			cout<<now.step<<" ";
			return ;
		}
		for(int i=0;i<8;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m)continue;
			if(vis[xx][yy]==3)continue;
			vis[xx][yy]=3;
			q.push(node(xx,yy,now.step+1));
		}
	}
	cout<<-1<<" ";
}
void bfsb()
{
    priority_queue<node>q;
	q.push(node(a,b,0));
	while(!q.empty())
	{
		node now=q.top();q.pop();
		int x=now.x;
		int y=now.y;
		if(x==c&&y==d)
		{
			cout<<now.step<<endl;
			return ;
		}
		for(int i=0;i<8;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			if(xx<1||xx>n||yy<1||yy>m)continue;
			if(vis[xx][yy]==1)continue;
			int X=x+ddx[i];
			int Y=y+ddy[i];
			if(vis[X][Y]==2)continue;
			vis[xx][yy]=1;
			q.push(node(xx,yy,now.step+1));
		}

	}
	cout<<-1<<endl;
}
void solve()
{
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>k>>a>>b>>c>>d;
	for(int i=1;i<=k;i++)
	{
		int x,y;
		cin>>x>>y;
		vis[x][y]=2;
	}
	bfsa();
    bfsb();
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int __;
	cin>>__;
	while(__--)solve();
}
/*
1 3 9 27
1
3
1 3
9
1 9
3 9
1 3 9
27
1 27
3 27
9 27
1 3 27
1 9 27
3 9 27
1 3 9 27


*/