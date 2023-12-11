/*！*/
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
vector<vector<int>>v;
bitset<maxn>vis;
int p[maxn];
int n,k,num;
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	v[num].push_back(x);
	int to=x+k;if(to>n)to-=n;
	dfs(to);
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	v.clear();
	num=0;
	vis.reset();
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		v.push_back(vector<int>{});
		dfs(i);
		num++;
	}
	for(int i=0;i<v.size();i++)
	{
		vector<int>&t=v[i];
		vector<int>s(t.size()+1);
	
	}
}
signed main(){
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}