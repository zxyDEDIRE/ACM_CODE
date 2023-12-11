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
vector<int>v[maxn];
bitset<maxn>vis;
int siz[maxn];
int dis[maxn];
int in[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		v[i].clear(),in[i]=0,dis[i]=0;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
		in[x]++;
		in[y]++;
	}
	queue<int>q;
	vis.reset();
	for(int i=1;i<=n;i++)
		if(in[i]==1)
			q.push(i),vis[i]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			if(vis[y])continue;
			dis[y]=dis[x]+1;
			vis[y]=1;
			q.push(y);
		}
	}
	int _x=0,_y=0;
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==1)_x++;
		if(dis[i]==0)_y++;
	}
	_y/=_x;
	cout<<_x<<" "<<_y<<endl;

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