/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=444;
struct node{
	int x,y,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
int dis[maxn][maxn];
bool vis[maxn][maxn];
vector<pii>d;
map<int,bool>mp;
int n,m;
void doit()
{
	for(int i=1;i<=m;i++)
	{
		int x=m-i*i;
		int y=sqrt(x);
		if(y*y==x)
		{
			x=i;
			if(x==y)
			{
				d.push_back({x,y});
				d.push_back({-x,y});
				d.push_back({x,-y});
				d.push_back({-x,-y});
			}
			else
			{
				d.push_back({x,y});
				d.push_back({-x,y});
				d.push_back({x,-y});
				d.push_back({-x,-y});
				d.push_back({y,x});
				d.push_back({-y,x});
				d.push_back({y,-x});
				d.push_back({-y,-x});
			}
		}
	}
}
void solve()
{
	cin>>n>>m;
	doit();
	priority_queue<node>q;
	q.push({1,1,0});
	while(!q.empty())
	{
		auto [x,y,D]=q.top();q.pop();
		if(vis[x][y])continue;
		vis[x][y]=1;
		dis[x][y]=D;
		for(auto [dx,dy]:d)
		{
			int xx=x+dx;
			int yy=y+dy;
			if(xx<1||yy<1||xx>n||yy>n)continue;
			q.push({xx,yy,D+1});
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(!vis[i][j])
				cout<<-1<<" ";
			else cout<<dis[i][j]<<" ";
		}
		cout<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	// ios::sync_with_stdio(false);
	// cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}