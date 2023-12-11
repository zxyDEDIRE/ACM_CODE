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
vector<int>v[maxn];
set<int>s[maxn];
map<int,int> dp[maxn];
int col[maxn];
int n;
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
		if(s[fa].size()>s[fb].size())swap(fa,fb);
		f[fa]=fb;
		s[fb].insert(s[fa].begin(),s[fa].end());
		s[fa].clear();
	}
}dsu;
void dfs(int x)
{
	if(col[x]!=0){
		dp[x][col[x]]=0,dp[x][0]=1;
		s[x].insert(col[x]);
		s[x].insert(0);
	}
	for(auto y:v[x]){
		dfs(y);
		if(!dsu.same(x,y))
			dsu.merge(x,y);
	}
	int F=dsu.find(x);
	for(auto i:s[F])
		dp[x][i]=0;
	for(auto y:v[x])
	{
		for(auto i:s[F]){
			if(dp[y].count(i))
			dp[x][i]+=min(dp[y][i],dp[y][0]);
		}
		dp[y].clear();
	}
		
	dp[x][0]=INF;
	
	for(auto i:s[F])
		if(i!=0)
		dp[x][0]=min(dp[x][0],dp[x][i]+1);
	// cout<<"X "<<x<<endl;
	// for(auto i:s[F])
	// 	cout<<"dp["<<i<<"]:"<<dp[x][i]<<" ";cout<<endl;
	// cout<<endl;
	// for(auto y:v[x]){
	// 	for(int i=1;i<=n;i++){
	// 		dp[x][i]+=min(dp[y][i],dp[y][0]);
	// 	}
	// }
	// for(int i=1;i<=n;i++)
	// 	dp[x][0]=min(dp[x][0],dp[x][i]+1);
}
void solve()
{
	cin>>n; 
	for(int i=2;i<=n;i++){
		int x;cin>>x;
		v[x].push_back(i);
	}
	dsu.init(n);
	for(int i=1;i<=n;i++)
		for(int j=0;j<=n;j++)
			dp[i][j]=INF;

	for(int i=1;i<=n;i++)
		cin>>col[i];
	dfs(1);
	// for(int i=1;i<=n;i++)
	// {
	// 	cout<<"I:"<<i<<"  ";
	// 	for(int j=0;j<=n;j++)
	// 		cout<<j<<":"<<dp[i][j]<<" ";cout<<endl;
	// }
	cout<<dp[1][0]<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}