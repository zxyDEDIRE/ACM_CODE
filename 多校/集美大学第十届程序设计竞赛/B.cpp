#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 1e5 + 10;
const ll inf = 1e18;

vector<pair<int, int> > g[N];
vector<int> G[N];
int n, m, sg[N];

struct node{
    int id; 
    ll dis;
    bool operator < (const node& A)const{
        return dis > A.dis;
    }
};

ll d[N];
bitset<N> vis;
priority_queue<node> q;
void djs(){
    for(int i = 1; i <= n; i ++) d[i] = inf;
    q.push({1, 0});
    vis.reset();
    d[1] = 0;
    while(!q.empty()){
        auto [u, dis] = q.top(); q.pop();
        if(vis[u]) continue ;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(d[v] > d[u] + w){
                d[v] = d[u] + w;
                q.push({v, d[v]});
            }
        }
    }

    vis.reset();
    q.push({n, d[n]});
    while(!q.empty()){
        auto [u, dis] = q.top(); q.pop();
        if(vis[u]) continue ;
        vis[u] = 1;
        for(auto [v, w] : g[u]){
            if(d[v] + w == d[u]){
                G[v].push_back(u);
                q.push({v, d[v]});
            }
        }
    }
}

int get_mex(vector<int>& mex){
    sort(mex.begin(), mex.end());
    int MEX = 0;
    for(auto x : mex){
        if(x == MEX) MEX ++;
        else if(x > MEX) return MEX;
    }
    return MEX;
}

int dfs(int u){
    if(sg[u] != -1) return sg[u];
    vector<int> mex;
    for(auto v : G[u]){
        mex.push_back(dfs(v));
    }
    return sg[u] = get_mex(mex);
}

void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++){
        g[i].clear();
        G[i].clear();
        sg[i] = -1;
    }
    for(int i = 1; i <= m; i ++){
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }

    djs();

    int ans = dfs(1);
    if(ans == 0) cout << "Little I is the winner.\n";
    else cout << "Little M is the winner.\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
