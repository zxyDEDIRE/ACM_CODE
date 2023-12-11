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
const int maxn=1e5+100;
struct node{
	map<int,int>cnt;set<int>se;int mx=0;
	void add(int x){
		cnt[x]++;
		if(cnt[x]>mx){
			mx=cnt[x];
			se.clear();
			se.insert(x);
		}
		else if(cnt[x]==mx)
			se.insert(x);
	}
	void clear(){
		if(mx<=1)return;
		cnt.clear();
		for(int it:se)
			cnt[it]=1;
		mx=1;
	}
}dt[maxn];
vector<int>v[maxn];
int col[maxn];
int id[maxn],tot;
int n,ans;
void dfs(int x)
{
	id[x]=++tot;
	if(col[x]){
		dt[id[x]].add(col[x]);
		return ;
	}
	int maxson=-1;
	int maxsiz=0;
	for(auto y:v[x])
	{
		dfs(y);
		if(dt[id[y]].se.size()>maxsiz)
			maxsiz=dt[id[y]].se.size(),maxson=y;
	}
	if(maxson!=-1)id[x]=id[maxson];
	for(auto y:v[x])
	{
		if(y==maxson)continue;
		for(auto i:dt[id[y]].se)
			dt[id[x]].add(i);
		dt[id[y]].clear();
	}
	ans+=v[x].size()-dt[id[x]].mx;
	dt[id[x]].clear();
}
void solve()
{
	cin>>n;
	for(int i=2,x;i<=n;i++)
	{
		cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		cin>>col[i];
	dfs(1);
	cout<<ans+1<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}