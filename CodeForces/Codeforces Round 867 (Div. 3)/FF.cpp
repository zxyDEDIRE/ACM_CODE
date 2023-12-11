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
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int dep[maxn];
int l[maxn];
int r[maxn];
int n,k,c;
void dfs(int x,int f,int C=k)
{
	for(auto y:v[x])
		if(y!=f)
			dep[y]=dep[x]+C,dfs(y,x,C);
}
void solve()
{
	cin>>n>>k>>c;
	for(int i=1;i<=n;i++)
		v[i].clear();
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dep[1]=0;dfs(1,1,1);
	for(int i=1;i<=n;i++)
		l[i]=dep[i];
	int fl_a=max_element(dep+1,dep+1+n)-dep;
	dep[fl_a]=0;dfs(fl_a,fl_a);
	for(int i=1;i<=n;i++)
		r[i]=dep[i];
	int fl_b=max_element(dep+1,dep+1+n)-dep;
	dep[fl_b]=0;dfs(fl_b,fl_b);
	int ans=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,max(r[i],dep[i])-c*l[i]);
	}
	cout<<ans<<endl;
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