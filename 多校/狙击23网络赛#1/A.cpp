/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int long long
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
int dep[maxn];
int siz[maxn];
ll res=0;
int n;
void dfs(int x,int fa=0)
{
	siz[x]=1;
	dep[x]=dep[fa]+1;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		siz[x]+=siz[y];
	}
}
void dfs1(int x,int fa,int a1,int a2,int ans)
{
	for(auto y:v[x])
	{
		if(y==fa)continue;
		int _ans=ans;
		_ans=_ans+a2-siz[y];
		res+=_ans;
		dfs1(y,x,a2,a1,_ans);
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep[0]=-1;
	dfs(1);
	int ans=0;
	int v1=0,v2=0;
	for(int i=1;i<=n;i++)
	{
		ans+=(dep[i]+1)/2;
		if(dep[i]&1)v1++;
		else v2++;
	}
	res+=ans;
	dfs1(1,0,v1,v2,ans);
	cout<<res/2<<endl;
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