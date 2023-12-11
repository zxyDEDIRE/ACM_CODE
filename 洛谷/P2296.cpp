/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
struct node{
	int x;ll dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[maxn],e[maxn];
int out[maxn],in[maxn];
bitset<maxn>vis;
int dis[maxn];
int n,m,s,t;
void dij()
{
	priority_queue<node>q;
	for(int i=1;i<=n;i++)
		dis[i]=0x3f3f3f3f;
	dis[s]=0;
	q.push({s,0});
	while(!q.empty())
	{
		auto [x,xx]=q.top();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		for(int i=0;i<v[x].size();i++)
		{
			int y=v[x][i];
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
	if(dis[t]==0x3f3f3f3f)cout<<-1<<endl;
	else cout<<dis[t]<<endl;
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		e[y].push_back(x);
		out[x]++;
	}
	cin>>s>>t;
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(out[i]==0&&i!=t)
			q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		vis[x]=1;
		for(auto y:e[x])
		{
			vis[y]=1;
		}
	}
	dij();
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}
/*
1 2 3
1

*/