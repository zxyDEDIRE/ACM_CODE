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
vector<int>ans;
bool vis[maxn];
int in[maxn];
int a[maxn];
int c[maxn];
int f[maxn];
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
void dfs(int x)
{
	if(vis[x])return ;
	vis[x]=1;
	ans.push_back(x);
	dfs(a[x]);
}
void solve()
{
	cin>>n;
	ans.clear();
	for(int i=1;i<=n;i++)
		in[i]=0,f[i]=i,vis[i]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i],in[a[i]]++;
		int fa=find(i);
		int fb=find(a[i]);
		if(fa!=fb)f[fa]=fb;
	}
	for(int j=1;j<=n;j++)
		cin>>c[j];
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=1;
		ans.push_back(x);
		in[a[x]]--;
		if(!in[a[x]])q.push(a[x]);
	}
	map<int,pii>mp;
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			int fa=find(i);
			if(!mp.count(fa))mp[fa]={INF,0};
			if(mp[fa].first>c[i])
				mp[fa]={c[i],i};
		}
	for(auto [x,y]:mp){
		dfs(a[y.second]);
	}
	for(auto i:ans)
		cout<<i<<" ";cout<<endl;

	// cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<i<<" "<<a[i]<<endl;
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