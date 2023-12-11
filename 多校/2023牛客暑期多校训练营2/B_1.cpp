#include <bits/stdc++.h>
#define IOS   ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define FOR(i, a, b) for (int (i) = (a); (i) <= (b); (i)++)
#define ROF(i, a, b) for (int (i) = (a); (i) >= (b); (i)--)
#define mem(a,b) memset(a,b,sizeof(a));
using namespace std;
#define ull unsigned long long
#define ll long long
#define endl '\n'
typedef pair<ll,ll> pll;
const int N=1e6+5;
const int mod=1e9+7;
/*-----------------------------------------------------------------------------------------------*/
const int inf = 1e9;
const int V=401000;
const  int E=401000;
struct Flow{
    int s,t,vtot;
    int head[V],etot;
    int cur[V],dis[V];
    struct edge{
        int v,nxt;
        ll f;//流量
    }e[E*2];
    void add(int u,int v,ll w1,ll w2=0){
        e[etot]={v,head[u],w1};head[u]=etot++;
        e[etot]={u,head[v],w2};head[v]=etot++;
    }
    bool bfs(){
        FOR(i,1,vtot)dis[i]=0,cur[i]=head[i];
        queue<int>q;
        q.push(s);dis[s]=1;
        while(!q.empty()){
            int u=q.front();q.pop();
            for(int i=head[u];~i;i=e[i].nxt){
                int v=e[i].v;
                if(e[i].f&&!dis[v]){
                    dis[v]=dis[u]+1;
                    if(v==t)return 1;
                    q.push(v);
                }
            }
        }
        return 0;
    }   

    ll dfs(int u,ll m){//m是当前流量
        if(u==t)return m;
        ll flow=0;
        for(int i=cur[u];~i;cur[u]=i=e[i].nxt)
            if(e[i].f&&dis[e[i].v]==dis[u]+1){
                ll f=dfs(e[i].v,min(m,e[i].f));
                e[i].f-=f;
                e[i^1].f+=f;
                m-=f;flow+=f;
                if(!m)break;
            }
        if(!flow)dis[u]=-1;
        return flow;   
    }   
    ll dinic(){
        ll flow=0;
        while(bfs())flow+=dfs(s,INT64_MAX);
        return flow;
    }
    void init(int s_,int t_,int vtot_){
        s=s_;t=t_;vtot=vtot_;etot=0;
        mem(head,-1);
    }
}F;
int tot=0;
vector<pair<int, int>>g[N];
const int M=2e5+5;
ll fat[M][21], id[M][21], dep[M], val[N], s, t;

void dfs(ll u,ll fa){
    dep[u]=dep[fa]+1; fat[u][0]=fa;
    for(int i=1;i<=15;i++){
        fat[u][i]=fat[fat[u][i-1]][i-1];
    }
    for(auto [v,w]:g[u]){
        if(v==fa)continue;
        val[v] = w;
        dfs(v,u);
    }
}
int LCA(ll u,ll v){ //得到祖先和路径最值
    if(dep[u]<dep[v])swap(u,v);
    ll mx=0;
    ROF(i,15,0)
        if(dep[fat[u][i]]>=dep[v]) u=fat[u][i];
    if(u==v)return u;
    ROF(i,15,0)
        if(fat[u][i]!=fat[v][i]) u=fat[u][i],v=fat[v][i];
    return fat[u][0];
}

int find(int x,int y){
    if(id[x][y])return id[x][y];
    id[x][y]=++tot;
    if(!y)F.add(tot, t, val[x]);
    else {
        F.add(id[x][y], find(x,y-1), inf);
        F.add(id[x][y], find(fat[x][y-1],y-1), inf);
    }
    return id[x][y];
}

signed main(){IOS
    int n, m; cin>>n>>m;
    for(int i=1; i<n; i++){
        int u, v, w; cin>>u>>v>>w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    s=n+1; t=n+2; tot=n+3;
    F.init(s,t,0);
    dfs(1,0);
    ll res = 0;
    while(m--){
        int x, y, a, b; cin>>x>>y>>a>>b;
        if(a<=b)continue;
        a-=b;
        res+=a;
        int tp = ++tot;
        F.add(s,tp,a);
        int g = LCA(x,y);
        for(int i=14; i>=0; i--)if((dep[x]-dep[g])>>i&1)F.add(tp, find(x,i), inf), x=fat[x][i];
        for(int i=14; i>=0; i--)if((dep[y]-dep[g])>>i&1)F.add(tp, find(y,i), inf), y=fat[y][i];
    }
    F.vtot = tot;
    cout<<res - F.dinic()<<endl;
    

    return 0;
}