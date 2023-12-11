/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
bool vis[666][666];
int n,m;
void doit(int x,int y)
{
	cout<<"Yes"<<endl;
	queue<pii>q;
	int cnt=0;
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=y;i++)
	{
		int xx=min(i,x);
		int yy=min(i,y);
		vis[xx][yy]=1;
		for(int k=0;k<4;k++)
		{
			int _x=xx+dx[k];
			int _y=yy+dy[k];
			if(_x>=1&&_y>=1&&_x<=x&&_y<=y&&!vis[_x][_y])
				q.push({_x,_y});
		}
		n--;
	}
	while(n)
	{
		auto [_x,_y]=q.front();q.pop();
		if(vis[_x][_y])continue;
		vis[_x][_y]=1;
		n--;
		for(int k=0;k<4;k++)
		{
			int xx=_x+dx[k];
			int yy=_y+dy[k];
			if(xx>=1&&yy>=1&&xx<=x&&yy<=y&&!vis[xx][yy])
				q.push({xx,yy});
		}
	}
	for(int i=1;i<=x;i++) 
		for(int j=1;j<=y;j++)
			if(vis[i][j])
				cout<<i<<" "<<j<<endl;
}
void solve()
{
	cin>>n>>m;
	if(m&1){cout<<"No"<<endl;return ;}
	m/=2;
	int flag=0;
	for(int x=1;x<=m/2;x++)
	{
		int y=m-x;
		if(n>=y&&n<=x*y)
		{
			flag=1;
			doit(x,y);
			break;
		}
	}
	if(flag==0)cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}