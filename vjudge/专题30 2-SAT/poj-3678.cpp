#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<bitset>
using namespace std;
const int maxn=1e6;
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
int out[maxn];
int in[maxn];
stack<int>s;
int n,m;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=0;i<v[x].size();i++)
	{
		int y=v[x][i];
		if(!dfn[y])
		{
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y,w;
		string str;
		cin>>x>>y>>w>>str;
		x++;y++;
		if(str=="AND")
		{
			if(w==1){
				v[x].push_back(x+n);
				v[y].push_back(y+n);
			}
			else{
				v[x+n].push_back(y);
				v[y+n].push_back(x);
			}
		}
		else if(str=="OR")
		{
			if(w==1){
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else{
				v[x+n].push_back(x);
				v[y+n].push_back(y);
			}
		}
		else if(str=="XOR")
		{
			if(w==1){
				v[x].push_back(y+n);
				v[y].push_back(x+n);
			}
			else{
				v[x].push_back(y);
				v[y].push_back(x);
				v[x+n].push_back(y+n);
				v[y+n].push_back(x+n);
			}
		}
	}
	for(int i=1;i<=n*2;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		if(col[i]==col[i+n]){
			cout<<"NO\n";
			return ;
		}
	cout<<"YES\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	solve();
	return 0;
}