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
const int INF=0x3f3f3f3f;
const int maxn=511;
vector<int>v[maxn];
bool vis[maxn][maxn];
int in[maxn];
int n,m;
void topsort()
{
	priority_queue<int,vector<int>,greater<int> >q;
	vector<int>ans;
	for(int i=1;i<=n;i++)
		if(!in[i])
			q.push(i);
	while(!q.empty())
	{
		int x=q.top();q.pop();
		ans.push_back(x);
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])q.push(y);
		}
	}
	for(int i=0;i<ans.size();i++)
	{
		cout<<ans[i];
		if(i!=ans.size()-1)cout<<" ";
	}
	cout<<endl;
}
void solve()
{
	while(cin>>n>>m)
	{
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
			v[i].clear(),in[i]=0;
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			if(!vis[x][y])
			{
				v[x].push_back(y);
				in[y]++;
			}
		}
		topsort();
	}
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
        solve();
    return 0;
}
