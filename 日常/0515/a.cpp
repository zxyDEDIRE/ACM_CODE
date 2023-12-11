#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=1e6;
vector<int>v[maxn];
int xx[maxn],yy[maxn];
int X,Y;
int n;
void dfs(int x,int fa)
{
	xx[x]=X--;
//	sort(v[x].begin(),v[x].end(),[&](int a,int b){return a>b;});
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(y==fa)continue;
		dfs(y,x);
	}
}
void dfsa(int x,int fa)
{
	yy[x]=Y--;
	for(int i=v[x].size()-1;i>=0;i--)
	{
		int y=v[x][i];
		if(y==fa)continue;
		dfsa(y,x);
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;X=Y=n;
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1,0);
	dfsa(1,0);
	cout<<endl;
	for(int i=1;i<=n;i++)
		cout<<xx[i]<<" "<<yy[i]<<"\n";
}
