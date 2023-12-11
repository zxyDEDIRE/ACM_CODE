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
vector<vector<int>>h;
int col[maxn];
int p[maxn];
int n,q,tot;
void dfs(int x,vector<int>&list)
{
	list.push_back(x);
	if(!vis[p[x]])
		dfs(p[x],list);
}
void solve()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		h.push_back(vector<int>());
		dfs(i,h[tot]);
		tot++;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
	return 0;
}
/*
1->2->4->3

1 2 3 4
1 2 3 4
2 4 1 3
4 3 2 1
3 1 4 2

*/