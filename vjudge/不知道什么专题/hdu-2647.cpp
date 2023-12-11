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
const int maxn=1e6;
vector<int>v[maxn];
bitset<maxn>vis;
int dis[maxn];
int in[maxn];
int n,m;
void topsort()
{
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(!in[i]){
			dis[i]=888;
			q.push(i);
		}
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
			{
				dis[y]=dis[x]+1;
				q.push(y);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=dis[i];
		if(in[i]){
			cout<<-1<<endl;
			return ;
		}
	}
	cout<<ans<<endl;
}
void solve()
{
	while(cin>>n>>m)
	{
		for(int i=1;i<=n;i++)
			dis[i]=in[i]=0,v[i].clear();
		vis.reset();
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			v[y].push_back(x);
			in[x]++;
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