#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
struct node{
	int x,y;};
vector<node>v[maxn];
vector<int>q;
bitset<maxn>vis;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			int x;cin>>x;
			v[x].push_back({i,j});
			if(!vis[x])q.push_back(x),vis[x]=1;
		}
	ll ans=0;
	for(int k=0;k<q.size();k++)
	{
		int x=q[k];
		for(int i=0;i<v[x].size()-1;i++)
			for(int j=i+1;j<v[x].size();j++)
				ans+=abs(v[x][i].x-v[x][j].x)+abs(v[x][i].y-v[x][j].y);
	}
	cout<<ans<<endl;

}