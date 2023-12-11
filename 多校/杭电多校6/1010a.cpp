#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
struct node
{
	int x,y;
}v[N];
int fa[N];
void init(int n)
{
	for(int i=1;i<=n;i++)fa[i]=i;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void solve()
{
	int n,m;
	cin>>n>>m;
	init(n);
	for(int i=1;i<=m;i++)
		cin>>v[i].x>>v[i].y;
	vector<int>G;
	for(int i=m;i>=1;i--)
	{
		int x=find(v[i].x),y=find(v[i].y);
		if(x==y)
		{
			G.push_back(i);
		}
		else 
		{
			fa[x]=y;
		}
	}
	cout<<G.size()<<'\n';
	for(int i=G.size()-1;i>=0;i--)cout<<G[i]<<" ";
	cout<<'\n';
}
int main()
{
	ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int __;cin>>__;
    while(__--)
        solve();
}