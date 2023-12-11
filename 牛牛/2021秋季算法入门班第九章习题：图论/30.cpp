/*
	嵌套变量重复
	特殊样例 0 1 2 n
	数组越界
	开long long
*/
#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ull=unsigned long long;
using ll=long long;
using pii=pair<int,int>;
const int dx[]={0,0,1,-1,1,-1,1,-1};
const int dy[]={1,-1,0,0,1,-1,-1,1};
const int mod=998244353;
const int inf=0x3f3f3f3f;
const int INF=1e9+7;
const int maxn=5e5+111;
const int N=1e6;
struct node{
	int x,mi,ans;
};
vector<int>v[maxn];
vector<int>G[maxn];
bitset<maxn>vis;
int low[maxn],dfn[maxn],col[maxn],tot,indx;
int mi[maxn],ma[maxn];
int in[maxn];
int a[maxn];
stack<int>s;
int n,m,S,T;
void tarjan(int x)
{
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(auto y:v[x])
	{
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
		++tot;
		int y;
		do{
			y=s.top();
			if(y==1)S=tot;
			if(y==n)T=tot;
			s.pop();
			vis[y]=0;
			col[y]=tot;
			mi[tot]=min(mi[tot],a[y]);
			ma[tot]=max(ma[tot],a[y]);
		}while(x!=y);
	}
}
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mi[i]=INF;
		ma[i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		int x,y,op;
		cin>>x>>y>>op;
		if(op==1)v[x].push_back(y);
		else v[x].push_back(y),v[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i);
	for(int i=1;i<=n;i++)
	{
		cout<<col[i]<<endl;
		for(auto y:v[i])
		{
			if(col[i]!=col[y])
			{
				G[col[i]].push_back(col[y]);
			}
		}
		v[i].clear();
	}
	for(int i=1;i<=tot;i++)
	{
		sort(G[i].begin(),G[i].end());
		if(G[i].size()>0)
		v[i].push_back(G[i][0]),in[G[i][0]]++;
		for(int j=1;j<G[i].size();j++)
			if(G[i][j]!=G[i][j-1])
				v[i].push_back(G[i][j]),in[G[i][j]]++;
	}
	for(int i=1;i<=n;i++)
		cout<<col[i]<<" ";cout<<endl;
	queue<node>q;
	q.push({S,mi[S],0});
	while(!q.empty())
	{
		auto [x,MI,ans]=q.front();q.pop();
		int res=max(res,ma[x]-M);
		cout<<x<<endl;
		if(x==T){
			cout<<ans<<endl;
		}
		for(auto y:v[x])
		{
			in[y]--;
			if(!in[y])
			{
				q.push({y,min(MI,mi[y]),max(ans,ma[x]-MI)});
			}
		}
	}
}
signed main(){
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.in.txt","r",stdin);
 // freopen("C:\\Users\\tob\\Desktop\\P4391_9.out.txt","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
		solve();
//  fclose(stdin);
//  fclose(stdout);
	return 0;
}
/*
3 3
8 9 4
1 2 1
2 3 1
3 1 1
*/