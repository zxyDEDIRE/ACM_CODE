/*
	嵌套变量是否相同
	特殊样例比如 0 1 2 n
	数组是否越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
const int maxn=1e6;
vector<int>v[maxn];
int dp[maxn];
int in[maxn];
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		in[y]++;
	}
	queue<int>q;
	for(int i=1;i<=n;i++)
		if(in[i]==0&&v[i].size())
		{
			dp[i]=1;
			q.push(i);
		}
	ll ans=0;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		if(v[x].size()==0)ans+=dp[x];
		for(auto y:v[x])
		{
			dp[y]+=dp[x];
			in[y]--;
			if(in[y]==0)
			{
				q.push(y);
			}
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