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
const int INF=0x3f3f3f3f;
const int maxn=111;
struct node{
	int id,dis;
	bool operator<(const node&a)const{
		return a.dis<dis;
	}
};
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int n,m,flag;
void dij(int s)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	vis.reset();
	dis[s]=0;
	priority_queue<node>q;
	q.push({s,0});
	while(!q.empty())
	{
		node it=q.top();q.pop();
		int x=it.id;
		if(vis[x])continue;
		vis[x]=1;
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push({y,dis[y]});
			}
		}
	}
	int ma=0;
	for(int i=1;i<=n;i++)
		ma=max(ma,dis[i]);
	if(ma>7)flag=0;
	// for(int i=1;i<=n;i++)
	// 	cout<<dis[i]<<" ";
	// cout<<endl;
}
void solve()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			v[i].clear();
		flag=1;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			x++;y++;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		for(int i=1;i<=n;i++)
		{
			dij(i);
			if(flag==0){
				cout<<"No"<<endl;
				break;
			}
		}
		if(flag)cout<<"Yes"<<endl;
	}
	

}
signed main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	solve();
	return 0;
}
/*
8 8
0 1
1 2
2 3
3 4
4 5
5 6
6 7
7 0
*/