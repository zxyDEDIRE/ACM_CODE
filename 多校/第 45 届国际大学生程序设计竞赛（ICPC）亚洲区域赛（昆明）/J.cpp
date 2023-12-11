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
vector<vector<int>>p;
vector<pii>ans[3];
bitset<maxn>vis;
int to[maxn];
int id[maxn];
int n,ma;
void dfs(int x,vector<int>&list)
{
	if(vis[x])return ;
	vis[x]=1;
	list.push_back(x);
	dfs(to[x],list);
}
void f(vector<int>&list)
{
	if(list.size()==1)return ;
	// for(auto i:list)
	// 	cout<<i<<" ";cout<<endl;
	ma=max(ma,1);
	int l=0,r=list.size()-1;
	vector<int>now;
	while(l<r)
	{
		int x=list[l];
		int y=list[r];
		ans[1].push_back({id[x],id[y]});
		swap(id[x],id[y]);
		if(id[x]!=x)now.push_back(x);
		if(id[y]!=y)now.push_back(y);
		l++,r--;
	}
	if(l==r)now.push_back(list[l]);
	for(auto i:now)
	{
		if(id[i]==i)continue;
		int x=i;
		int y=id[x];
		ans[2].push_back({id[x],id[y]});
		swap(id[x],id[y]);
		ma=max(ma,2);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>to[i],id[to[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		p.push_back(vector<int>());
		dfs(i,p.back());
	}
	for(auto list:p)
		f(list);


	cout<<ma<<endl;
	for(int i=1;i<=ma;i++)
	{
		cout<<ans[i].size()<<" ";
		for(auto [x,y]:ans[i])
			cout<<x<<" "<<y<<" ";
		cout<<endl;
	}
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
7
7 1 2 3 4 5 6

6
4 1 2 3 6 5

*/