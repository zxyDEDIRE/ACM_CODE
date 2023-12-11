#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>G[maxn],v[maxn];
int dis[maxn];
int n,ans;
void dfs1(int x,int fa)
{
	dis[x]=1;
	for(auto y:G[x])
	{
		if(y==fa)continue;
		v[x].push_back(y);
		dfs1(y,x);
		dis[x]+=dis[y];
	}
}
void dfs(int x)
{
	if(v[x].size()==1)
	{
		ans+=dis[v[x][0]]-1;
		return ;
	}
	else if(v[x].size()==2)
	{
		int a=dis[v[x][0]];
		int b=dis[v[x][1]];
		if(a>b)
		{
			ans+=a-1;
			dfs(v[x][1]);
		}
		else if(b>a)
		{
			ans+=b-1;
			dfs(v[x][0]);
		}
		else if(a==b)
		{
			if(v[v[x][0]].size()>=v[v[x][1]].size())
			{
				ans+=a-1;
				dfs(v[x][1]);
				return ;
			}
			else
			{
				ans+=b-1;
				dfs(v[x][0]);
				return ;
			}
		}
	}
}
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)G[i].clear(),v[i].clear();
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs1(1,1);
	ans=0;
	dfs(1);
	cout<<ans<<endl;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int __;cin>>__;
	while(__--)
		solve();
}
/*
1
4
1 2
1 3
2 4

7
1 2
1 5
2 3
2 4
5 6
5 7
*/