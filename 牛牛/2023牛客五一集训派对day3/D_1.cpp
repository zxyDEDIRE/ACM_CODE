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
const int N=600;

int n,m;
struct node_1{
	bool vis[N][N];
	bool mp[N][N];
	void doit(int x,int y)
	{
		memset(mp,0,sizeof(mp));
		memset(vis,0,sizeof(vis));
		cout<<"Yes"<<endl;
		for(int i=1;i<=max(x,y);i++)
		{
			int xx=min(x,i);
			int yy=min(y,i);
			mp[xx][yy]=1;
			n--;
		}
		queue<pii>q;
		q.push({1,1});
		while(n)
		{
			auto [_x,_y]=q.front();q.pop();
			if(vis[_x][_y])continue;
			vis[_x][_y]=1;
			if(!mp[_x][_y])mp[_x][_y]=1,n--;
			for(int i=0;i<4;i++)
			{
				int xx=_x+dx[i];
				int yy=_y+dy[i];
				if(xx<1||yy<1||xx>x||yy>y)continue;
				if(vis[xx][yy])continue;
				q.push({xx,yy});
			}
		}
		for(int i=1;i<=x;i++) 
			for(int j=1;j<=y;j++)
				if(mp[i][j])
					cout<<i<<" "<<j<<endl;
	}
}A;

void solve()
{
	cin>>n>>m;
	if(m&1){cout<<"No"<<endl;return ;}

	m/=2;
	for(int i=1;i<=m/2;i++)
	{
		int x=i,y=m-i;
		if(n>=max(x,y)&&n<=x*y)
		{
			A.doit(x,y);
			return ;
		}
	}
	cout<<"No"<<endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
2
79 120
34 146
*/