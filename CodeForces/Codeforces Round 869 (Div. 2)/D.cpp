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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
const int N=2e3+10;
vector<int>v[maxn];
vector<pii>ans;
set<pii>s;
bitset<N>mp[N],vis;
int n,m,ok;
int out(int x)
{
	int cnt=0;
	ans.clear();
	for(auto y:v[x])
		if(!mp[x][y]&&cnt<2&&!vis[y]){
			ans.push_back({x,y}),cnt++;
		}
	if(cnt!=2)return 0;
	for(auto [x,y]:s)
		ans.push_back({x,y});
	return 1;
} 
void dfs(int x,int rt)
{
	if(ok)return ;
	vis[x]=1;
	int flag=0;
	for(auto y:v[x])
	{
		if(y==rt&&!ok)
		{
			mp[x][y]=mp[y][x]=1;
			s.insert({x,y});
			ok=out(rt);
			return ;
		}
		if(mp[x][y])continue;
		if(vis[y])continue;
		mp[x][y]=mp[y][x]=1;
		s.insert({x,y});
		dfs(y,rt);
		s.erase({x,y});
		mp[x][y]=mp[y][x]=0;
	}
}
void solve()
{
	cin>>n>>m;
	ans.clear();
	s.clear();
	vis.reset();
	ok=0;
	for(int i=1;i<=n;i++)
		v[i].clear(),mp[i].reset();
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(v[i].size()>=4&&!ok)
		{
			dfs(i,i);
		}
	if(!ok)cout<<"NO"<<endl;
	else
	{
		cout<<"YES"<<endl;
		cout<<ans.size()<<endl;
		for(auto [x,y]:ans)
			cout<<x<<" "<<y<<endl;
	}
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