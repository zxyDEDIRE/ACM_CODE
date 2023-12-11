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
const int maxn=1e6+100;
const long long INF = 1e10;
struct Edge {
    int v, r;
    long long f;
};
struct _Flow {
    vector<long long> h, gap, e;
    long long ht, tag;
    vector<list<long long>> lst;
    vector<vector<Edge>> g;
    void init(int pcnt) {
        g.clear();
        g.resize(pcnt + 1);
        ht = tag = 0;
    }
    void add(int x,int y,long long w){
        g[x].push_back({y,(int)g[y].size(),w});
    }
    void Add(int x, int y, long long w) {
        g[x].push_back({y, (int)g[y].size(), w});
        g[y].push_back({x, (int)g[x].size()-1, 0});
        // return {y,(int)g[y].size()-1};
    }
    void update(int p, long long th) {
        tag ++;
        if (h[p] < INF)gap[h[p]] --;
        h[p] = th;
        if (th >= INF)
            return;
        ht = th;
        gap[th] ++;
        if (e[p])lst[th].push_back(p);
    }
    void bfs(int s, int t, int pcnt) {
        h.clear();
        gap.clear();
        queue<int> q;
        h.resize(pcnt + 2);
        gap.resize(pcnt + 2);
        lst.clear();
        lst.resize(pcnt + 2);
        fill(h.begin(), h.end(), INF);
        h[s] = pcnt;
        e[s] = INF;
        h[t] = tag = 0;
        q.push(t);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (auto &e : g[u]) {
                int v = e.v;
                if (h[v] == INF && g[v][e.r].f)
                    update(v, h[u] + 1), q.push(v);
            }
            ht = h[u];
        }
    }
    void pushflow(int u, Edge &cur) {
        int v = cur.v;
        if (!e[v]){
            lst[h[v]].push_back(v);
        }
        long long flow = min(cur.f, e[u]);
        e[u] -= flow, e[v] += flow;
        cur.f -= flow;
        g[v][cur.r].f += flow;
    }
    void push(int u, int pcnt) {
        long long th = INF;
        for (auto &cur : g[u]) {
            int v = cur.v;
            if (cur.f) {
                if (h[v] + 1 == h[u]) {
                    pushflow(u, cur);
                    if (e[u] <= 0)
                        return;
                } else
                    th = min(th, h[v] + 1);
            }
        }
        if (h[u] < INF && gap[h[u]] > 1)
            update(u, th);
        else {
            for (int i = 1; i <= pcnt; i++) {
                if (h[i] > h[u])
                    update(i, INF);
            }
            update(u, INF);
        }
    }
    long long maxFlow(int s, int t, int pcnt) {
        long long lim = pcnt * ceil(sqrt(pcnt));
        e.clear();
        e.resize(pcnt + 1);
        bfs(s, t, pcnt);
        for (auto &cur : g[s]){
            pushflow(s, cur);
        }
        for (; ~ht; ht --) {
            while (!lst[ht].empty()) {
                int u = lst[ht].back();
                lst[ht].pop_back();
                push(u, pcnt);
                if (tag > lim)
                    bfs(s, t, pcnt);
            }
        }
        return e[t];
    }
} f;

char mp[11][11];
int a[11][11];
int b[11][11];
int n;
void solve()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>mp[i][j];
	f.init(100);
	int tot=0;
	int s=++tot,t=++tot;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(mp[i][j]=='.'&&mp[i][j]!=mp[i][j-1])
				a[i][j]=++tot,f.Add(s,tot,1);
			else if(mp[i][j]=='.')
				a[i][j]=tot;
	}

	for(int j=1;j<=n;j++)
	{
		for(int i=1;i<=n;i++)
			if(mp[i][j]=='.'&&mp[i][j]!=mp[i-1][j])
				b[i][j]=++tot,f.Add(tot,t,1);
			else if(mp[i][j]=='.')
				b[i][j]=tot;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			if(mp[i][j]=='.'){
				f.Add(a[i][j],b[i][j],1);
			}
	}
	cout<<f.maxFlow(s,t,tot)<<endl;
}
signed main(){
 // freopen("data.in","r",stdin);
 // freopen("data.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	while(cin>>n&&n)
		solve();
	return 0;
}