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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
bitset<maxn>ned;
int ned_num[maxn];
int dp[maxn][55];
int n,m,k,num;
void dfs1(int x,int fa)
{
	int son=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs1(y,x);
		son+=ned_num[y];
	}
	ned_num[x]+=son;
	if(ned_num[x])num+=2;
}
void solve()
{
	cin>>n>>k;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		int x;cin>>x;
		ned[x]=1;
	}
	dfs1(1,0);
	num-=2;
	cout<<num<<endl;
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