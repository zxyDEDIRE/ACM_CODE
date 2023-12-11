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
vector<int>v[maxn],e[maxn];
int in[maxn],out[maxn];
int a[maxn],b[maxn];
int aa,bb;
int n,m;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[y].push_back(x);
		in[x]++;
		out[x]++;
	}
	queue<int>q;

	for(int i=1;i<=n;i++)
		if(!in[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		a[x]=++aa;
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])q.push(y);
		}
	}


	for(int i=n;i>=1;i--)
		if(!out[i])q.push(i);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		b[x]=++bb;
		for(int i=v[x].size()-1;i>=0;i--)
		{
			int y=v[x][i];
			out[y]--;
			if(!out[y])q.push(y);
		}
	}


	// for(int i=1;i<=n;i++)
	// 	cout<<a[i]<<" ";cout<<endl;
	// for(int i=1;i<=n;i++)
	// 	cout<<b[i]<<" ";cout<<endl;

	int cnt=0;
	for(int i=1;i<=n;i++)
		if(a[i]==b[i])cnt++;
	cout<<cnt<<endl;
}
int main()
{	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
	return 0;
}