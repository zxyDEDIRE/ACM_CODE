/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
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
struct node{
	int x,y,w;
}t[maxn];
vector<pii>v[maxn];
vector<int>G[maxn];
vector<node>p;
int sum[maxn];
int f[maxn];
set<int>st;
int n;
int find(int r){
	return f[r]=f[r]==r?f[r]:find(f[r]);
}
int S1,dep1=0;
void dfs1(int x,int fa,int dep)
{
	if(dep>dep1)
		S1=x,dep1=dep;
	for(auto [y,w]:v[x])
		if(y!=fa)
			dfs1(y,x,dep+w);
}
int S2,dep2=0;
void dfs2(int x,int fa,int dep)
{
	if(dep>dep2)
		S2=x,dep2=dep;
	for(auto [y,w]:v[x])
		if(y!=fa)
			dfs2(y,x,dep+w);
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k,x;cin>>k;
		while(k--){
			cin>>x;
			sum[i]+=x;
			st.insert(x);
			G[x].push_back(i);
		}
	}
	for(auto x:st)
	{
		sort(G[x].begin(),G[x].end());
		for(int i=0;i<G[x].size();i++)
			for(int j=i+1;j<G[x].size();j++)
				p.push_back({G[x][i],G[x][j],(sum[G[x][i]]^sum[G[x][j]])+1});
	}
	sort(p.begin(),p.end(),[&](node a,node b){
		if(a.w!=b.w)return a.w<b.w;
		if(a.x!=b.x)return a.x<b.x;
		return a.y<b.y;
	});
	for(int i=1;i<=n;i++)
		f[i]=i;
	int cnt=0;
	for(auto [x,y,w]:p)
	{
		int fa=find(x);
		int fb=find(y);
		if(fa!=fb)
		{
			cnt++;
			f[fa]=fb;
			v[x].push_back({y,w});
			v[y].push_back({x,w});
		}
	}
	if(cnt!=n-1){
		cout<<0<<endl;
		return ;
	}
	dfs1(1,0,0);
	dfs2(S1,0,0);
	cout<<dep2<<endl;


	
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