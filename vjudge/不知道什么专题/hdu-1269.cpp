/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
int dfn[maxn],low[maxn],indx;
int in[maxn],out[maxn];
int col[maxn],tot;
vector<int>v[maxn];
bitset<maxn>vis;
stack<int>s;
int n,m;
void init()
{
	for(int i=1;i<=n;i++)
	{
		v[i].clear();
		dfn[i]=low[i]=0;
	}
	tot=indx=0;
	while(s.size())s.pop();
	vis.reset();
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
			y=s.top();s.pop();
			vis[y]=0;
		}while(x!=y);
	}
}
void solve()
{
	while(cin>>n>>m&&n)
	{
		init();
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i);
		if(tot!=1)cout<<"No"<<endl;
		else cout<<"Yes"<<endl;
	}
	
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}