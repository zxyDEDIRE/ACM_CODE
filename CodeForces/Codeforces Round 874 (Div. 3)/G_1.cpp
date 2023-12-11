
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
vector<pii>v[maxn];
int dp[maxn][3];
bitset<maxn>vis;
vector<int>ans;
int flag;
int n;
int dfs(int x,int fa=0)
{
	vector<int>u;
	for(auto [y,w]:v[x])
	{
		if(y==fa)continue;
		int now=dfs(y,x);
		if(now)u.push_back(now);
		else if(now==0)
			ans.push_back({w});
	}
	if(u.size()>2)flag=0;

	if(u.size()==0)return 1;
	else if(u.size()==1&&u[0]==1)
		return 2;
	else if(u.size()==1&&u[0]==2)
		return 0;
	else if(u.size()==1)flag=0;
	else if(u.size()==2&&u[0]==1&&u[1]==1)
		return 0;
	else flag=0;
	return 10;
}
void solve()
{
	cin>>n;
	ans.clear();
	flag=1;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back({y,i});
		v[y].push_back({x,i});
	}
	int now=dfs(1);
	if(now!=0&&flag==0||n<3)cout<<-1<<endl;
	else
	{
		cout<<ans.size()<<endl;
		sort(ans.begin(),ans.end());
		for(auto i:ans)
			cout<<i<<" ";cout<<endl;
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