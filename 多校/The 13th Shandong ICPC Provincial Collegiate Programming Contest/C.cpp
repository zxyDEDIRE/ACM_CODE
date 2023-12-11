#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
using pvi=pair<vector<int>,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>dep[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
char ans[maxn];
int rk[maxn];
int n,m;
void init(){
	for(int i=0;i<=n;i++){
		v[i].clear();
		dep[i].clear();
		rk[i]=0;
	}
	vis.reset();
}
void dfs1(int x,int d)
{
	dep[d].push_back(x);
	for(auto y:v[x])
		dfs1(y,d+1);
}
void dfs2(int x)
{
	vector<pii>res;
	for(auto y:v[x]){
		dfs2(y);
		res.push_back({rk[y],y});
	}
	sort(res.begin(),res.end());
	char nk='a';
	for(auto [x,y]:res)
		ans[y]=nk++;
}
void solve()
{
	cin>>n>>m;
	init();
	for(int i=1;i<=n;i++){
		int x;cin>>x;
		v[x].push_back(i);
	}
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		vis[x]=1;
	}
	dfs1(0,0);
	for(int i=n;i>=1;i--)
	{
		if(dep[i].size()==0)continue;
		vector<pvi>res;
		for(auto x:dep[i])
		{
			vector<int>now;
			if(vis[x])now.push_back(0);
			for(auto y:v[x])
				now.push_back(rk[y]);
			sort(now.begin(),now.end());
			res.push_back({now,x});
		}
		sort(res.begin(),res.end(),[&](pvi &a,pvi &b){
			for(int i=0;i<a.first.size()&&i<b.first.size();i++)
				if(a.first[i]!=b.first[i])
					return a.first[i]<b.first[i];
			return a.first.size()>b.first.size();
		});
		int nk=1;
		int len=res.size();
		for(int i=0;i<len;i++){
			rk[res[i].second]=nk;
			if(i+1<len&&res[i].first!=res[i+1].first)
				nk++;
		}
		// cout<<"DEP: "<<i<<endl;
		// for(auto [x,y]:res){
		// 	cout<<y<<" "<<rk[y]<<" ";
		// 	for(auto I:x)
		// 		cout<<I;
		// 	cout<<endl;
		// }
		// cout<<endl;
	}
	dfs2(0);
	for(int i=1;i<=n;i++)
		cout<<ans[i];
	cout<<endl;
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
1 
7 5
0 0 1 1 2 2 3
3 4 5 6 7
*/