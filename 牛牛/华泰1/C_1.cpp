#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,-1};
const int dy[]={1,-1,0,0};
using pii=pair<int,int>;
const int INF=1e9+7;
const int maxn=1e5+10;
const int N=50;
char mp[N][N];
int dis[N][N];
pii p[maxn];
pii ans[maxn];
vector<pii>a;
deque<pii>q;
string str;
int n,m;
int cnt=0,mi;
void dfs(int x,int y,int _x,int _y,int step=0)
{
	if(step>dis[x][y])return ;
	dis[x][y]=min(dis[x][y],step);
	if(x==_x&&y==_y)
	{
		if(step<mi)
		{
			mi=step;
			cnt=1;
			p[step]={x,y};
			for(int i=0;i<=step;i++)
				ans[i]=p[i];
		}
		else if(mi==step)cnt++;
		return ;
	}
	for(int i=0;i<4;i++)
	{
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx<1||yy<1||xx>n||yy>m)continue;
		if(mp[xx][yy]=='*')continue;
		p[step]={x,y};
		dfs(xx,yy,_x,_y,step+1);
	}
}
int ok(int x,int y,int _x,int _y)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[x][y]=0;
	cnt=0;
	mi=INF;
	dfs(x,y,_x,_y,0);
	// cout<<x<<" "<<y<<" "<<_x<<" "<<_y<<endl;
	if(cnt!=1){
		// cout<<"cnt!=1"<<endl;
		return 0;
	}

	int l=0;
	int r=a.size();
	for(int i=0;i<=mi;i++)
	{
		if(l<r&&ans[i]==a[l])l++;
	}
	// for(auto i:a)
	// 	cout<<i.first<<" "<<i.second<<endl;

	if(l!=r){
	// cout<<"l!=r"<<endl;
		return 0;
	}
	// cout<<"OK"<<endl;

	return 1;
}
void solve()
{
	cin>>n>>m;
	int sx,sy;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			cin>>mp[i][j];
			if(mp[i][j]=='R')
				sx=i,sy=j;
		}
	cin>>str;

	int x=sx,y=sy;
	int _x=sx,_y=sy;
	int num=0;
	a.clear();
	// str=str+"A";
	for(auto i:str)
	{
		if(i=='W')sx--;
		else if(i=='S')sx++;
		else if(i=='A')sy--;
		else if(i=='D')sy++;

		if(!ok(x,y,sx,sy))
		{
			// cout<<"NO"<<endl;
			num++;
			a.clear();
			x=_x;
			y=_y;
		}
		_x=sx;
		_y=sy;
		a.push_back({_x,_y});
		// cout<<endl;
	}

	cout<<num+1<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}