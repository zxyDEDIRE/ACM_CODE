/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e3;
int dfn[maxn],low[maxn],col[maxn],indx,tot;
vector<int>G[maxn];
vector<int>v[maxn];
bitset<maxn>vis;
int val[maxn];
int w[maxn];
stack<int>s;
int n,m,cnt;
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
	if(dfn[x]==low[x])
	{
		tot++;
		int y;
		do{
			y=s.top();
			s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
		cin>>val[i];
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		if(x)
			v[x].push_back(i);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(auto y:v[x])
			if(col[x]!=col[y])
				G[col[x]].push_back(col[y]);
		v[x].clear();
		sort(G[x].begin(),G[x].end());
		if(G[x].size())v[x].push_back(G[x][0]);
		for(int i=1;i<G[x].size();i++)
			if(G[x][i]!=G[x][i-1])
				v[x].push_back(G[x][i]);
	}
	
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}