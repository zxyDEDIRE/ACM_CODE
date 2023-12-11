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
int dep[maxn];
int num[maxn][25];
int f[maxn][25];
int n;
void dfs(int x,int fa)
{	
	dep[x]=dep[fa]+1;
	f[x][0]=fa;
	for(int i=1;i<=20;i++)
		f[x][i]=f[f[x][i-1]][i-1];
	num[x][0]=1;
	for(int i=1;i<=20;i++)
		num[x][i]=num[f[x][i-1]][i-1]+
	for(auto y:v[x])
		if(y!=fa)
			dfs(y,x);
}
int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	for (int j = 0, d = dep[x] - dep[y]; d; ++j, d >>= 1)
		if (d & 1) x = f[x][j];
	if(x==y)return x;
	for (int j = 20; ~j; --j)
		if (f[x][j] != f[y][j])
			x = f[x][j], y = f[y][j];
	return f[x][0];
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
	dfs(1,0);
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __;cin>>__;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}