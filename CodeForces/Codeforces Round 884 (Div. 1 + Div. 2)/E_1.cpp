#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define pb push_back

using namespace std;

const int N = 4e3 + 10;
int par[N];
inline int find(int x) { return x == par[x] ? x : par[x] = find(par[x]); }
void merge(int x, int y) {
    x = find(par[x]), y = find(par[y]);
    if(x == y) return ;
    par[x] = y;
}
struct node { int x, val; };

signed main() {

    if(fopen("yl.in", "r")) {
        freopen("yl.in", "r", stdin);
        freopen("yl.out", "w", stdout);
    }

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T --) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<vector<node>> vec(m);
        -- n, -- m;
        rep(i,1,n << 1) par[i] = i;
        int a, b, c, d;
        rep(i,1,k) {
            cin >> a >> b >> c >> d;
            if(a + 1 == c && b + 1 == d) {
                vec[b].pb({a, 1});
            } else {
                vec[d].pb({a, 2});
            }
        }
        rep(i,1,m) {
            int sz = vec[i].size();
            rep(j,1,sz - 1) {
                if(vec[i][j].val == vec[i][0].val){
                    merge(vec[i][0].x, vec[i][j].x);
                    merge(vec[i][0].x + n, vec[i][j].x + n);
                }
                else {
                    merge(vec[i][0].x, vec[i][j].x + n);
                    merge(vec[i][0].x + n, vec[i][j].x);
                }
            }
        }
        bool flg = true;
        rep(i,1,n) {
            if(find(i) == find(i + n)) {
                flg = false;
                break;
            }
        }
        cout << (flg ? "YES" : "NO") << endl;
    }
    return 0;
}