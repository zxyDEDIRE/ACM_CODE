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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct node{
	int x,y;
}p[maxn];
vector<int>mp[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
int mt[maxn];
int fa[maxn];
int n;
int dfs(int x)
{
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:v[x])
		if(!mt[y]||dfs(mt[y])){
			mt[y]=x;
			return 1;
		}
	return 0;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(i);
		v[y].push_back(i);
	}
	for(int i=1;;i++)
	{
		vis.reset();
		if(!dfs(i)){
			cout<<i-1<<endl;
			return ;
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}