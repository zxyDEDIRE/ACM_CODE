/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
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
set<int>x_in,y_in;
map<int,int>x_id,y_id;
bitset<maxn>vis;
map<pii,int>id;
int val[maxn];
int dis[maxn];
pii p[maxn];
int h,w,n,tot;
void in(int x,int y){
	if(!x_in.count(x))x_id[x]=++tot,x_in.insert(x);
	if(!y_in.count(y))y_id[y]=++tot,y_in.insert(y);
}
int dfs(int x,int w)
{
	int ma=0;
	for(auto y:v[x])
	{
		if(vis[y])continue;
		if(y<=n&&val[y]<=w)continue;
		vis[y]=1;
		ma=max(ma,1+dfs(y,max(w,val[y])));
		vis[y]=0;
	}
	return ma;
}
void solve()
{
	cin>>h>>w>>n;
	tot=n;
	for(int i=1;i<=n;i++)
	{
		int x,y,w;
		cin>>x>>y>>val[i];
		p[i]={x,y};
		in(x,y);
		v[x_id[x]].push_back(i);
		v[i].push_back(x_id[x]);

		v[y_id[x]].push_back(i);
		v[i].push_back(y_id[x]);
	}
	for(int i=1;i<=n;i++)
	{
		vis[i]=1;
		dis[i]=dfs(i,val[i]);
		vis[i]=0;
		cout<<dis[i]<<endl;
		break;
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