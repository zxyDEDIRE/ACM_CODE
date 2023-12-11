#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int INF=1e9+7;
const int maxn=1e6+100;
vector<int>v[maxn];
int vis[maxn];
int pre[maxn];
int dis[maxn];
int a[maxn];
int n;
void dij(int s,int t)
{
	for(int i=1;i<=n;i++)
		dis[i]=INF;
	queue<int>q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(vis[x])continue;
		vis[x]=1;
		if(x==t){
			cout<<dis[t]<<endl;
			return ;
		}
		for(auto y:v[x])
		{
			if(dis[y]>dis[x]+1)
			{
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(pre[a[i]]!=0)
			v[pre[a[i]]].push_back(i);
		pre[a[i]]=i;
		if(i<n)
		{
			v[i].push_back(i+1);
			v[i+1].push_back(i);
		}
	}
	dij(1,n);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}
/*
11
1 2 2 4 5 5 1 3 3 3 4 
*/