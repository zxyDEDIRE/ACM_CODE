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
vector<int>v[maxn];
vector<int>G[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
int out[maxn];
int in[maxn];
stack<int>s;
int n,m;
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
	if(dfn[x]==low[x])
	{
		++tot;
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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		v[i].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(auto y:v[i])
			if(col[i]!=col[y])
				G[col[y]].push_back(col[i]);
	for(int i=1;i<=tot;i++)
	{
		v[i].clear();
		sort(G[i].begin(),G[i].end());
		if(G[i].size())v[i].push_back(G[i][0]),in[G[i][0]]++;
		for(int j=2;j<G[i].size();j++)
			if(G[i][j]!=G[i][j-1])
				v[i].push_back(G[i][j]),in[G[i][j]]++;
	}
	queue<int>q;
	for(int i=1;i<=tot;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(auto y:v[x])
		{
			num[y]+=num[x];
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<num[col[i]]<<endl;
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