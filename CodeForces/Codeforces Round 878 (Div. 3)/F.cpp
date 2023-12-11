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
const int dx[]={0,0,1};
const int dy[]={0,1,0};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
void solve()
{
	int n,m,r;
	cin>>n>>m>>r;
	map<pp(3),bool>mp;
	map<pp(3),bool>vis;
	for(int i=1;i<=r;i++)
	{
		int t,op,x;
		cin>>t>>op>>x;
		mp[{t,op,x}]=1;
	}
	auto bfs=[&]()->int{
		queue<pp(3)>q;
		q.push({0,0,0});
		while(!q.empty())
		{
			auto [x,y,t]=q.front();q.pop();
			if(x==n&&y==m)return t;
			for(int i=0;i<3;i++)
			{
				int xx=x+dx[i];
				int yy=y+dy[i];
				int tt=t+1;
				if(tt>xx+yy+r||xx>n||yy>m)continue;
				if(mp.count({tt,1,xx})||mp.count({tt,2,yy})||vis.count({xx,yy,tt}))continue;
				vis[{xx,yy,tt}]=1;
				q.push({xx,yy,tt});
			}
		}
		return -1;
	};
	cout<<bfs()<<endl;
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