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
struct Edge{
	int to,next,w;
}edge[maxn];
int head[maxn],cnt=1;
int dfn[maxn],low[maxn],indx;
bitset<maxn>vis;
stack<int>s;
int n,m,bcc_cnt;

vector<pii>v[maxn];
int tot;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa)
{
	dfn[x]=low[x]=++indx;
	vis[x]=1;
	s.push(x);
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y]){
				mp[{x,y}]=edge[i].w;
			}
			if(low[y]>=dfn[x])
			{
				bcc_cnt++;
				int _v;
				v[bcc_cnt].push_back({x,0});
				v[x].push_back({bcc_cnt,0});
				do{

					v[bcc_cnt].push_back({_v,0});
					v[_v].push_back({bcc_cnt,0});
					_v=s.top();s.pop();
				}while(_v!=y);
			}
		}
		else if(vis[y]&&dfn[y]<dfn[x]&&i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
}
void solve()
{
	cin>>n>>m;
	cnt=1;
	bcc_cnt=n;
	for(int i=1;i<=m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	tarjan(1,0);
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