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
struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],cnt=1;
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int cut[maxn];
int in[maxn];
int n,m;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
		}
		else if(y!=x)
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		int y;
		tot++;
		do{
			y=s.top();
			s.pop();
			col[y]=tot;
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	tarjan(1,0);
	for(int x=1;x<=n;x++)
		for(int i=head[x];i;i=edge[i].next)
			if(col[x]!=col[edge[i].to])
				in[col[edge[i].to]]++;
	int ans=0;
	for(int i=1;i<=tot;i++)
		if(in[i]==1)
			ans++;
	cout<<(ans+1)/2<<endl;

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
        solve();
    return 0;
}