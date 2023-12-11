#include <bits/stdc++.h>
using namespace std;

typedef vector<int> Vec;
typedef pair<int, int> pii;
const int N = (1 << 19);

int t, n, m, k;
int val[200];
int d[100][100];
string s[100][100];

int get_id(int x, int y){
    return x * m + y;
}
pii get_pii(int id){
    return {id / m, id % m};
}

int f[N]; // 删除状态表示的对象最大价值
// void cmax(int& a,int b){ a = max(a, b); }

bool check(int id){ // 空false 不空true
    auto [x, y] = get_pii(id);
    return s[x][y][0] != '-'; 
}
bool check(int id1, int id2, Vec& vis){
    auto [x1, y1] = get_pii(id1); 
    auto [x2, y2] = get_pii(id2);

    int add = 1;
    if(y2 < y1) add = -1; 
    
    int flag = 1;
    // 先下再 左/右
    for(int i = x1 + 1; i <= x2 && flag; i ++){
        if(i == x2 && y1 == y2) return true;
        if(!vis[get_id(i, y1)] && s[i][y1][0] != '-') flag = 0; // 路径上没被删除并且不为空 不合法
    }
    for(int j = y1; j <= y2 && flag; j ++){
        if(j == y2) return true;
        if(!vis[get_id(x2, j)] && s[x2][j][0] != '-') break;
    }
    
    // 先左/右 再下
    flag = 1;
    for(int j = y1 + 1; j <= y2 && flag; j ++){
        if(j == y2 && x1 == x2) return true;
        if(!vis[get_id(x1, j)] && s[x1][j][0] != '-') break;
    }
    for(int i = x1; i <= x2; i ++){
        if(i == x2) return true;
        if(!vis[get_id(i, y2)] && s[i][y2][0] != '-') break;
    }
    return false;
}

void solve(){
    cin >> n >> m >> k;

    for(int i = 0; i < n; i ++){
        for(int j = 0; j < m; j ++) cin >> s[i][j];
    }
    for(int i = 0; i <= k; i ++) cin >> val[i];

    for(int i = 0; i < n; i ++) for(int j = 0; j < m; j ++) if(s[i][j][0] != '-') {
        for(int o = 0; o < n; o ++) for(int u = 0; u < m; u ++) if(s[o][u][0] != '-') {
            int sum = 0;
            for(int r = 0; r < k; r ++) sum += (s[i][j][r] == s[o][u][r]);
            int id1 = get_id(i, j), id2 = get_id(o, u);
            d[id1][id2] = d[id2][id1] = val[sum];
        }
    }

    t = n * m;
    for(int i = 1; i < (1 << t); i ++) f[i] = -1;

    int id = 0;
    for(int i = 0; i < (1 << t); i ++){
        if(f[i] == -1) continue ;
        Vec vis = vector<int>(20, 0);
        for(int j = 0; j < t; j ++){
            vis[j] = (i >> j & 1);
        }

        for(int j = 0; j < t; j ++){
            if(vis[j] || !check(j)) continue ; // 删除 或 为空
            for(int p = j + 1; p < t; p ++){
                if(!vis[p] && check(p) && check(j, p, vis)){ // 未删除，不为空，能连线
                    id = max(id, i | (1 << j) | (1 << p));
                    // f[i|(1<<j)|(1<<p)] = max(f[i|(1<<j)|(1<<p)],f[i]+d[j][p]);
                    cmax(f[i|(1<<j)|(1<<p)],            f[i]+d[j][p]); // RE
                }
            }
        }
    }
    cout << f[id] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
