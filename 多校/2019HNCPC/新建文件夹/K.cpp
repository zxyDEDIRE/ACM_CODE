#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
const int maxn=1e6+100;
vector<int>v[maxn];
vector<int>ans;
int top[maxn];
int tal[maxn];
int n,m;
void dfs(int x,int fa)
{
	ans.push_back(x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa)continue;
		dfs(y,x);
	}
}
void solve()
{
	ans.clear();
	for(int i=1;i<=n;i++)
	{
		top[i]=i;
		tal[i]=i;
		v[i].clear();
	}
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		if(top[x]==0)
		{
			top[x]=tal[y];
			tal[x]=top[y];
			top[y]=tal[y]=0;
		}
		else if(top[y]==0)
		{
			swap(top[x],tal[x]);
		}
		else
		{
			v[tal[x]].push_back(top[y]);
			v[top[y]].push_back(tal[x]);
			tal[x]=tal[y];
			swap(tal[x],top[x]);
			tal[y]=top[y]=0;
		}
	}
	if(top[1]!=0)
		dfs(top[1],0);
	cout<<ans.size()<<" ";
	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	cout<<"\n";
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
	while(cin>>n>>m)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}