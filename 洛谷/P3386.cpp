#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1e6;
vector<int>v[maxn];
int mh[maxn],vis[maxn];
int n,m,e,num;
bool dfs(int x,int fa)
{	if(vis[x]==fa)return 0;
	vis[x]=fa;
	for(int i=0;i<v[x].size();i++)
		if(mh[v[x][i]]==0||dfs(mh[v[x][i]],fa)){
			mh[v[x][i]]=x;
			return 1;
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
	for(int i=1;i<=n;i++)
		if(dfs(i,i))num++;
	cout<<num;
}
