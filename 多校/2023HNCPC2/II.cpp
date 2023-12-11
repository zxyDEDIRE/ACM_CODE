#include<bits/stdc++.h>
using namespace std;
using ll =long long;
#define double long double
#define forn(name,s,e) for(int name=(s);name<=(int)(e);++name)
using ii=pair<int,int>;
using vi=vector<int>;
#define pb push_back
const ll MS=400010,INF=0x3f3f3f3f;
std::vector<int> G[MS], T[MS];
int N,M,cnt;
int dfn[MS], low[MS], dfc,in[MS];
int stk[MS], tp;

void Tarjan(int u) {
	low[u] = dfn[u] = ++dfc;                // low 初始化为当前节点 dfn
	stk[++tp] = u;                          // 加入栈中
	for (int v : G[u]) {                    // 遍历 u 的相邻节点
		if (!dfn[v]) {                        // 如果未访问过
			Tarjan(v);                          // 递归
			low[u] = std::min(low[u], low[v]);  // 未访问的和 low 取 min
			if (low[v] == dfn[u]) {  // 标志着找到一个以 u 为根的点双连通分量
				++cnt;                 // 增加方点个数
				// 将点双中除了 u 的点退栈，并在圆方树中连边
				for (int x = 0; x != v; --tp) {
					x = stk[tp];
					T[cnt].push_back(x);
					T[x].push_back(cnt);
					in[x]++;
					in[cnt]++;
				}
				// 注意 u 自身也要连边（但不退栈）
				T[cnt].push_back(u);
				T[u].push_back(cnt);
				in[cnt]++;
				in[u]++;
			}
		} else
			low[u] = std::min(low[u], dfn[v]);  // 已访问的和 dfn 取 min
	}
}
int sz[MS],dfm[MS],pp,trsz[MS],he[MS],fa[MS][20];
void dfs(int u,int f)
{
	he[u]=he[f]+1;
	dfm[u]=++pp;
	sz[u]=1;
	trsz[u]=(u<=N);
	fa[u][0]=f;
	for(int i=1;i<20;i++)
		fa[u][i]=fa[fa[u][i-1]][i-1];
	for(auto v:T[u]){
		if(v==f)continue;
		dfs(v,u);
		sz[u]+=sz[v];
		trsz[u]+=trsz[v];
	}
}
/*
void ddfs(int u,int f,int g){
	top[u]=g;
	fa[u]=f;
	if(son[u])ddfs(son[u],u,g);
	for(auto v:T[u]){
		if(v==son[u]||v==f)continue;
		ddfs(v,u,v);
	}
 }*/
int lca(int u,int v){
	int x=he[v]-he[u]-1;
	for(int i=19;i>=0;i--)
	{
		if((x>>i)&1)
			v=fa[v][i];
	}
	return v;
}
bool check(int u,int v){
	int l=dfm[u],r=dfm[u]+sz[u]-1;
	return l<=dfm[v]&&dfm[v]<=r;
}
void solve()
{
	cin>>N>>M;
	cnt = N;  // 点双 / 方点标号从 N 开始
	for (int i = 1; i <= M; ++i) {
		int u, v;
		cin>>u>>v;
		G[u].push_back(v);  // 加双向边
		G[v].push_back(u);
	}
	// 处理非连通图
	for (int u = 1; u <= N; ++u)
		if (!dfn[u]) Tarjan(u), --tp;
	// 注意到退出 Tarjan 时栈中还有一个元素即根，将其退栈

	int q;
	cin>>q;
	dfs(1,0);
	forn(i,1,q){
		int u,v;
		cin>>u>>v;
		if(he[u]>he[v])swap(u,v);
		if(in[u]==1&&in[v]==1){
			printf("%d\n",N);
		}
		else if(in[u]!=1&&in[v]==1){
			if(check(u,v))printf("%d\n",trsz[lca(u,v)]+1);
			else printf("%d\n",N-trsz[u]+1);
		}
		else if(in[v]!=1&&in[u]==1){
			if(check(v,u))printf("%d\n",trsz[v]);
			else printf("%d\n",N-trsz[v]+1);
		}
		else {
			if(check(u,v))printf("%d\n",trsz[lca(u,v)]-trsz[v]+2);
			else printf("%d\n",N-trsz[u]-trsz[v]+2);
		}
	}
	forn(i,1,cnt)G[i].clear(),T[i].clear(),dfn[i]=in[i]=0;
	dfc=cnt=tp=pp=0;
	//memset(fa,0,sizeof(fa));
}
int main()
{
   	cin.tie(0),cout.tie(0);
	ios_base::sync_with_stdio(0);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	
	
}
/*
2
  5 5
  1 2
  1 3
  2 4
  4 5
  2 5
  5
  1 2
  1 4
  2 3
  2 5
  3 5
  
  5 5
  1 2
  1 3
  2 3
  2 4
  3 5
  99
  
 */