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
bool vis[111][111];
int in[maxn];
int p[maxn];
int w[maxn];
int n,m,flag;
void dfs(int now)
{
	if(flag)return ;
	if(now>n){
		flag=1;
		return ;
	}
	int x=p[now];
	if(w[x]==0)dfs(now+1);
	else
	{
		for(auto y:v[x])
		{
			if(vis[x][y]||vis[y][x])continue;
			if(w[y]==0)continue;
			vis[x][y]=vis[y][x]=1;
			w[x]--;
			w[y]--;
			dfs(now);
			vis[x][y]=vis[y][x]=0;
			w[x]++;
			w[y]++;
		}
	}
}
void solve()
{
	for(int i=1;i<=n;i++)
		cin>>w[i],p[i]=i,v[i].clear();
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	sort(p+1,p+1+n,[&](int a,int b){
		return v[a].size()<v[b].size();
	});
	flag=0;
	dfs(1);
	if(flag)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}