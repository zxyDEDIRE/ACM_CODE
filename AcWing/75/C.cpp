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
vector<int>v[maxn];
int fa[maxn];
int n,s,t;
void dfs(int x,int f)
{
	fa[x]=f;
	for(auto y:v[x])
	{
		if(y==f)continue;
		dfs(y,x);
	}
}
void solve()
{
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++)
	{
		if(i==s)continue;
		int x;cin>>x;
		v[x].push_back(i);
		v[i].push_back(x);
	}
	dfs(t,0);
	for(int i=1;i<=n;i++)
	{
		if(i==t)continue;
		cout<<fa[i]<<" ";
	}
	cout<<endl;
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