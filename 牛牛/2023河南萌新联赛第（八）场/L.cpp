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
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
vector<int>d[maxn];
int dep[maxn];
int f[maxn];
ll w[maxn];
int max_dep;
int n,m;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void dfs(int x,int fa)
{
	dep[x]=dep[fa]+1;
	d[dep[x]].push_back(x);
	max_dep=max(max_dep,dep[x]);
	int flag=0;
	for(auto y:v[x])
		if(y!=fa){
			flag=1;
			dfs(y,x);
		}
	if(!flag)w[f[x]]++;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		f[i]=i;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		int fa=find(x);
		int fb=find(y);
		f[fa]=fb;
	}
	for(int i=1;i<=n;i++)
		find(i);
	dfs(1,0);
	for(int de=max_dep;de>1;de--)
	{
		auto &p=d[de];
		for(auto x:p)
		{
			for(auto y:v[x])
			{
				if(dep[y]==dep[x]-1)
				{
					(w[f[y]]+=w[f[x]])%=mod;
				}
			}
		}
	}
	// for(int i=1;i<=n;i++)
	// 	cout<<i<<" "<<f[i]<<" "<<w[f[i]]<<endl;
	cout<<w[1]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}