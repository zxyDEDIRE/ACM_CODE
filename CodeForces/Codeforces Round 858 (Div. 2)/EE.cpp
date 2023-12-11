/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e5+100;
vector<unordered_map<int,int>>v;
unordered_map<int,int>vis;
int fa[maxn];
int a[maxn];
int n,q,tot;
ll dfs(int x,int y)
{
	if(x>y)swap(x,y);
	if(x==1)return a[x]*a[x];
	if(vis.count(x)&&v[vis[x]].count(y))return v[vis[x]][y];
	if(!vis.count(x))v.push_back(unordered_map<int,int>{}),vis[x]=v.size()-1;
	return v[vis[x]][y]=a[x]*a[y]+dfs(fa[x],fa[y]);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=2;i<=n;i++)
		cin>>fa[i];
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,y)<<endl;
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}