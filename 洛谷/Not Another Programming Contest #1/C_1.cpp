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
int dfn[maxn],low[maxn],col[maxn],num[maxn],indx,tot;
bitset<maxn>vis;
bitset<maxn>Ok;
pii p[maxn];
stack<int>s;
int n,d,c;
void init()
{

}
bool ok(int _x,int _y)
{
	pii a=p[_x];
	pii b=p[_y];
	long long h=(ll)(a.second+d-b.second);
	long long w=(ll)(a.second-b.second);
	if(w<0)w=-w;
	if(w>h)return 0;
	return 1;
}
void dfs(int x)
{
	Ok[x]=1;
	for(auto y:v[x])
		if(!Ok[y])
			dfs(y);
}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto y:v[x])
	{
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		tot++;
		int y;
		do{
			y=s.top();
			s.pop();
			vis[y]=0;
			col[y]=tot;
			num[tot]++;
		}while(y!=x);
	}
}
void solve()
{
	cin>>n>>d>>c;
	init();
	for(int i=1;i<=n;i++)
		cin>>p[i].first>>p[i].second;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j&&ok(i,j))
				v[i].push_back(j);
	dfs(c);
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])
		{
			if(!vis[x]||!vis[y])continue;
			
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	int __,A;cin>>__>>A;
	while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}