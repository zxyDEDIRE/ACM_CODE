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
int dfn[maxn],low[maxn],indx;
int col[maxn],col_tot;
int in[maxn];
stack<int>s;
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
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
		}
		else if(i!=(fa^1))
			low[x]=min(low[x],dfn[y]);
	}
	if(low[x]==dfn[x])
	{
		col_tot++;
		int y;
		do{
			y=s.top();
			s.pop();
			col[y]=col_tot;
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
		add(x,y);
		add(y,x);
	}
	tarjan(1,0);
	for(int x=1;x<=n;x++)
	{
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(col[x]!=col[y])
				in[col[y]]++;
		}
	}
	int res=0;
	for(int i=1;i<=col_tot;i++)
		if(in[i]==1)res++;
	cout<<(res+1)/2<<endl;
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