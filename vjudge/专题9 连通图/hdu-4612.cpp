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
vector<int>v[maxn];
int head[maxn],cnt;
int dfn[maxn],low[maxn],indx;
int col[maxn],tot;
bitset<maxn>vis;
stack<int>s;
int n,m;
int sum,ans,root,depth;
void init(){
	for(int i=1;i<=n;i++)
	{
		dfn[i]=low[i]=vis[i]=head[i]=0;
		v[i].clear();
	}
	indx=tot=0;
	cnt=1;
	sum=0;
	ans=INF;
}
void add(int from,int to){
	edge[++cnt].to=to;
	edge[cnt].next=head[from];
	head[from]=cnt;
}
void tarjan(int x,int fa){
	dfn[x]=low[x]=++indx;
	s.push(x);
	vis[x]=1;
	for(int i=head[x];i;i=edge[i].next){
		int y=edge[i].to;
		if(!dfn[y]){
			tarjan(y,i);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<low[y])
				sum++;
		}
		else if(i!=(fa^1) && vis[y])
			low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x]){
		++tot;
		int y;
		do{
			y=s.top();s.pop();
			vis[y]=0;
			col[y]=tot;
		}while(x!=y);
	}
}
int dfs(int x)
{
	vis[x]=1;
	int ma=-1,mb=-1;
	for(auto y:v[x])
	{
		if(vis[y])continue;
		int now=dfs(y);
		mb=max(mb,now);
		if(mb>ma)swap(ma,mb);
	}
	ans=min(ans,sum-ma-mb);
	return ma+1;
}
void solve()
{
	// cin>>n>>m;
	init();
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	for(int i=1;i<=n;i++)
		if(!dfn[i])
			tarjan(i,0);
	for(int x=1;x<=n;x++)
		for(int i=head[x];i;i=edge[i].next){
			int y=edge[i].to;
			if(col[x]!=col[y])
				v[col[x]].push_back(col[y]);
		}
	int now=dfs(1);
	ans=min(ans,sum-now);
	cout<<ans<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n>>m&&n!=0)
		solve();
	return 0;
}
/*
7 7
1 2
2 3
3 4
2 5
5 6
2 7
7 2
0 0
*/