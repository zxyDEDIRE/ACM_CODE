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
const int maxn=1e4+100;
struct node{
	int x;vector<int>y;
	bool operator<(const node&a)const{
		if(a.x!=x)return a.x>x;
		return a.y>y;
	}
};
set<node>S;
vector<pii>v[maxn];
vector<node>ans;
bool vis[maxn];
int n,m,k,s,t;
void dfs(int x,vector<int>dis={},int sum=0)
{
	if(S.size()==k)
	{
		if(sum>(*S.rbegin()).x)return ;
		if(dis>(*S.rbegin()).y)return ;
	}
	if(x==t)
	{		
		S.insert({sum,dis});
		if(S.size()>k)S.erase(*S.rbegin());
		return ;
	}
	for(auto [y,w]:v[x])
	{
		if(vis[y])continue;
		vector<int>now=dis;
		now.push_back(y);
		vis[y]=1;
		dfs(y,now,sum+w);
		vis[y]=0;
	}
}
void solve()
{
	cin>>n>>m>>k>>s>>t;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		cin>>x>>y>>w;
		v[x].push_back({y,w});
	}
	vis[s]=1;
	dfs(s,{s});
	if(S.size()<k){
		cout<<"No"<<endl;
		return ;
	}
	// for(auto A:S)
	// {
	// 	cout<<A.x<<endl;
	// 	for(auto x:A.y)
	// 		cout<<x<<" ";cout<<endl;
	// }
	// cout<<endl;
	vector<int>res=(*S.rbegin()).y;
	for(int i=0;i<res.size();i++)
	{
		cout<<res[i];
		if(i!=res.size()-1)
			cout<<"-";
	}
	cout<<endl;
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