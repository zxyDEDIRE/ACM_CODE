/*
    嵌套变量重复
    特殊样例 0 1 2 n
    数组越界
    开long long
*/
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<map>
#include<set>
using namespace std;
#define endl "\n"
typedef long long ll;
typedef pair<int,int> pii;
const int INF=0x3f3f3f3f;
const int maxn=1e6;
vector<int>v[maxn];
int low[maxn],dfn[maxn],indx;
bitset<maxn>vis;
int col[maxn];
int num[maxn];
int in[maxn];
int out[maxn];
stack<int>s;
int n,m,tot;
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
	if(low[x]==dfn[x])
	{
		int y;
		++tot;
		do{
			num[tot]++;
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(y!=x);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
		for(int j=0;j<v[i].size();j++)
			if(col[i]!=col[v[i][j]])
				out[col[i]]++;
	int flag=-1;
	int cnt=0;
	for(int i=1;i<=tot;i++)
		if(!out[i])flag=i,cnt++;
	if(cnt!=1)cout<<0<<endl;
	else cout<<num[flag]<<endl;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

        solve();
    return 0;
}