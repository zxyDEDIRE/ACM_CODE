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
bitset<maxn>v1,v2;
int p1[maxn];
int p2[maxn];
int n,m;
void dfs1(int x)
{
	v1[x]=1;
	sort(v[x].begin(),v[x].end(),[&](int a,int b){
		return rand()%2;
	});
	for(auto y:v[x])
	{
		if(v1[y])continue;
		p1[y]=p1[x]+1;
		dfs1(y);
	}
}
void dfs2(int x)
{
	v2[x]=1;
	sort(v[x].begin(),v[x].end(),[&](int a,int b){
		return rand()%2;
	});
	for(auto y:v[x])
	{
		if(v2[y])continue;
		p2[y]=p2[x]+1;
		dfs2(y);
	}
}
void solve()
{
	cin>>n>>m;
	srand(time(0));
	for(int i=1;i<=n;i++)
		v[i].clear();
	v1.reset();
	v2.reset();
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	p1[1]=p2[1]=0;
	dfs1(1);
	dfs2(1);
	for(int i=1;i<=n;i++)
		if(p1[i]!=p2[i]){
			cout<<"No"<<endl;
			return ;
		}
	cout<<"Yes"<<endl;
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