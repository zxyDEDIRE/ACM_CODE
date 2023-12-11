/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn];
vector<int>G[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int num[maxn];
int in[maxn];
int n,m;
void NO(){cout<<"No"<<endl;}
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
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
			col[y]=tot;
			num[tot]++;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	tot=0;
	vis.reset();
	indx=0;
	while(!s.empty())s.pop();
	for(int i=1;i<=n;i++)
	{
		in[i]=0;
		col[i]=0;
		num[i]=0;
		v[i].clear();
		G[i].clear();
		dfn[i]=low[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(int i=0;i<v[x].size();i++)
			if(col[x]!=col[v[x][i]])
				G[col[x]].push_back(col[v[x][i]]);
		v[x].clear();
	}
	for(int x=1;x<=n;x++)
	{
		sort(G[x].begin(),G[x].end());
		if(G[x].size())v[x].push_back(G[x][0]),in[G[x][0]]++;
		for(int i=1;i<G[x].size();i++)
			if(G[x][i]!=G[x][i-1])
				v[x].push_back(G[x][i]),in[G[x][i]]++;
	}
	queue<int>q;
	while(!q.empty())q.pop();
	for(int i=1;i<=tot;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		if(q.size()>1)return NO();
		int x=q.front();q.pop();
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			in[y]--;
			if(!in[y])
				q.push(y);
		}
	}
	cout<<"Yes"<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int __;cin>>__;
    while(__--)
        solve();
    return 0;
}