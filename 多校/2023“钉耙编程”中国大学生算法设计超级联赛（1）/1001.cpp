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
vector<int>v[maxn];
int dep1[maxn];
int dep2[maxn];
int p1[maxn];
int p2[maxn];
int n,m;
void dfs1(int x,int fa)
{
	dep1[x]=dep1[fa]+1;
	p1[x]=fa;
	for(auto y:v[x])
		if(y!=fa)
			dfs1(y,x);
}
void dfs2(int x,int fa)
{
	dep2[x]=dep2[fa]+1;
	p2[x]=fa;
	for(auto y:v[x])
		if(y!=fa)
			dfs2(y,x);
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	while(m--)
	{
		int s1,s2,t1,t2;
		cin>>s1>>t1>>s2>>t2;
		dfs1(s1,0);
		dfs2(s2,0);
		map<int,bool>mp;
		int x=t1;
		do{
			mp[x]=1;
			x=p1[x];
		}while(x!=s1);
		cout<<dep1[t1]*2<<endl;
	}

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