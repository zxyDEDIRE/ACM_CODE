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
bitset<maxn>vis;
int p[maxn];
vector<int>v,u;
int n;
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	v.push_back(x);
	dfs(p[x]);
}
void solve()
{
	cin>>n;
	vis.reset();
	u.clear();
	int ans=n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		if(i==p[i])continue;
		v.clear();
		dfs(i);

		sort(v.begin(),v.end());
		for(int i=1;i<v.size();i++)
			u.push_back(v[i]-v[i-1]);
	}
	if(u.size())
	{
		ans=u[0];
		for(auto i:u)
			ans=__gcd(ans,i);
	}
	
	cout<<ans<<endl;
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
/*
11
1 11 6 4 8 3 7 5 9 10 2
2 11
6 3
8 5
*/