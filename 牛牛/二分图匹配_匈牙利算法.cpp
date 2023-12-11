#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int mt[maxn];
int n,m,e;
bitset<maxn>vis;
bool dfs(int x,int fa)
{
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:v[x]){
		if(!mt[y]||dfs(mt[y],fa)){
			mt[y]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		vis.reset();
		if(dfs(i,i))ans++;
	}
	cout<<ans<<endl;
}