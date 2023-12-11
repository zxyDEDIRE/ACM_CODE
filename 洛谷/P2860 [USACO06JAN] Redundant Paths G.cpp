/*
	嵌套变量重复 特殊样例 0 1 2 n 数组越界 开long long
	清空 建图别用vector
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define pp(x) array<int,x>
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
using pdd=pair<double,double>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=1e6+100;
struct Edge{
	int to,next;
}edge[maxn];
int head[maxn],cnt=1;
vector<int>v[maxn];
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
int in[maxn];
stack<int>s;
int n,m;
void add(int from,int to)
{
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa=0)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].to;
		if(!dfn[y])
		{
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y]&&i!=(fa^1)&&dfn[y]<dfn[x])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		++tot;
		int y;
		do{
			y=s.top();
			s.pop();
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
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next)
		{
			int y=edge[i].to;
			if(col[x]!=col[y])
			{
				v[col[x]].push_back(col[y]);
				v[col[y]].push_back(col[x]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		auto &p=v[i];
		sort(p.begin(),p.end());
		p.erase(unique(p.begin(),p.end()),p.end());
		for(auto y:p)
			in[y]++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(in[i]==1)
			cnt++;
	cnt=(cnt+1)/2;
	cout<<cnt<<endl;

}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P1000_0.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	// int __;cin>>__;
	// while(__--)
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}