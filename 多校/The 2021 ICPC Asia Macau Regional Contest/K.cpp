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
vector<int>e[maxn];
class DSU{
public:
	vector<int>f,num;
	DSU(){}
	void init(int n){
		f.resize(n+1);
		iota(f.begin(),f.end(),0);
	}
	int find(int r){
		return f[r]=f[r]==r?f[r]:find(f[r]);
	}
	bool same(int x,int y){
		return find(x)==find(y);
	}
	void merge(int x,int y){
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
			f[fa]=fb;
	}
}dsu;
pii p[maxn];
int n,m;
bool dfs(int x,vector<int>&ans,int t,int fa)
{
	if(x==t)return 1;
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa)continue;
		int fl=dfs(y,ans,t,x);
		if(fl){
			ans.push_back(e[x][i]);
			return fl;
		}
	}
	return 0;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		e[i].clear();
	}
	for(int i=1;i<=m;i++)
		cin>>p[i].first>>p[i].second;
	dsu.init(n);
	vector<int>ans;
	int flag=0;
	for(int i=1;i<=m;i++)
	{
		auto [x,y]=p[i];
		if(!dsu.same(x,y))
		{
			dsu.merge(x,y);
			v[x].push_back(y);
			e[x].push_back(i);
			v[y].push_back(x);
			e[y].push_back(i);
		}
		else
		{
			flag=1;
			dfs(x,ans,y,0);
			ans.push_back(i);
			break;
		}
	}
	sort(ans.begin(),ans.end());
	if(flag)
	{
		for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i];
			if(i!=ans.size()-1)cout<<" ";
		}
	}
	else
		cout<<"-1";
	
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--){
		solve();
		if(__)cout<<"\n";
	}
	return 0;
}