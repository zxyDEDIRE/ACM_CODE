#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
const int maxn=111;
char mp[maxn][maxn];
bool vis[maxn][maxn][5];
int n,sx,sy,tx,ty,mi=1e6;

struct node{
	int x,y,step,fl;string str;
	node(int a,int b,int c,int d,string e){
		x=a,y=b,step=c,fl=d;str=e;
	}
};
void bfs()
{
	deque<node>q;
	q.push_front(node(sx,sy,0,4,"1"));
	q.push_front(node(sx,sy,0,4,"2"));
	q.push_front(node(sx,sy,0,4,"3"));
	q.push_front(node(sx,sy,0,4,"0"));
	for(int i=0;i<4;i++)
	//	for(int j=0;j<4;j++)
			vis[sx][sy][i]=1;
	while(!q.empty())
	{
		node now=q.front();q.pop_front();
		int x=now.x;
		int y=now.y;
		if(x==tx&&y==ty){
		//	cout<<now.step<<" "<<now.str<<endl;
			mi=min(mi,now.step);
			continue;
		}
		for(int i=0;i<4;i++)
		{
			int xx=x+dx[i];
			int yy=y+dy[i];
			int fl=now.fl;
			int step=now.step;
			if(xx<1||xx>n||yy<1||yy>n)continue;
			if(vis[xx][yy][i])continue;
			if(mp[xx][yy]=='x')continue;
			vis[xx][yy][i]=1;
			if(fl==4)q.push_front(node(xx,yy,step,i,now.str+(char)(i+'0')));
			else  if(i!=now.fl)q.push_back(node(xx,yy,step+1,i,now.str+(char)(i+'0')));
			else q.push_front(node(xx,yy,step,i,now.str+(char)(i+'0')));
			
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			cin>>mp[i][j];
			for(int k=0;k<4;k++)
			//	for(int kk=0;kk<4;kk++)
					vis[i][j][k]=0;
			if(mp[i][j]=='A')sx=i,sy=j;
			if(mp[i][j]=='B')tx=i,ty=j;
		}
	mi=1e9;
	bfs();
	if(mi==1e9)cout<<-1<<endl;
	else 	cout<<mi<<endl;
}
int main(){
	int __;cin>>__;
	while(__--)solve();
}
/*
1
7
A.xxxxx
.x...xx
.x...B.
.x.x.x.
...x.x.
.xxxxx.
.......


*/