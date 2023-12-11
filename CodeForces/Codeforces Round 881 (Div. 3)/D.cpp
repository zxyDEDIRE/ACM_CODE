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
int siz[maxn];
int n,q;
void dfs(int x,int fa=0)
{
	int flag=0;
	siz[x]=0;
	for(auto y:v[x])
	{
		if(y==fa)continue;
		dfs(y,x);
		flag=1;
		siz[x]+=siz[y];
	}
	if(!flag)siz[x]=1;
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);
	cin>>q;
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<1ll*siz[x]*siz[y]<<endl;
	}
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