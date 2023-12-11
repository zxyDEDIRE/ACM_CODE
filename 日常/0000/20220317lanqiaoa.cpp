#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6;
vector<int>v[maxn];
vector<int>q;
bool vis[maxn];
int in[maxn];
int n,k;
void dfs(int x)
{
	if(k<=0)return ;
	if(vis[x])return ;
	vis[x]=1;
	k--;
	q.push_back(x);
	for(auto i:v[x])
		dfs(i);
}
signed main()
{
    LONG_LONG_MAX
	cin>>n>>k;
	for(int i=1,x,y;i<n;i++){
		cin>>x>>y;
		v[x].push_back(y);in[x]++;
		v[y].push_back(x);in[y]++;
	}
	for(int i=1;i<=n;i++)
		if(in[i]==1){
			dfs(i);
			break;
		}
	sort(q.begin(),q.end());
	for(int i=0;i<q.size();i++)
		if(i!=q.size()-1)cout<<q[i]<<" ";
		else cout<<q[i];
}