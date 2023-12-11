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
const int maxn=1e6;
vector<int>v[maxn];
int cnt[maxn];
bitset<maxn>vis;
int p[maxn];
int k,n,m;
void solve()
{
	cin>>k>>n>>m;
	for(int i=1;i<=k;i++)
		cin>>p[i];
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	int ans=0;
	for(int I=1;I<=k;I++)
	{
		vis.reset();
		queue<int>q;
		q.push(p[I]);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			if(vis[x])continue;
			vis[x]=1;
			cnt[x]++;
			if(cnt[x]==k)ans++;
			for(auto y:v[x])
				q.push(y);
		}
	}
	cout<<ans<<endl;


}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}