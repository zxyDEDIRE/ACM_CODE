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
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6;
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int num[maxn];
int out[maxn];
int in[maxn];
stack<int>s;
int n,m,w;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=1;i<v[x].size();i++)
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
	cin>>n>>m>>w;
	for(int i=1;i<=n;i++)
		
}
signed main(){
//  freopen("in1.txt","r",stdin);
//  freopen("out1.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}