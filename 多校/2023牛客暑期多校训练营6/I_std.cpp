#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
const int N = 1e6 + 100;

int n, m;
vector<int> edges[N], path;
int colors[N];

int fa[N], dep[N], vis[N], is_tar[N];

int now;

int target;

void dfs(int x) {
    vis[x] = 1;
    is_tar[x] = (colors[x] == target);
    for (auto y : edges[x]) {
        if (vis[y]) {
            continue;
        }
        fa[y] = x;
        dep[y] = dep[x] + 1;
        dfs(y);
        is_tar[x] &= is_tar[y];
    }
}

void DP(int x, int tar) {
    for (auto y : edges[x]) {
        if (fa[y] != x) {
            continue;
        }
        while (is_tar[y] == 0) {
            colors[y] ^= 1;
            path.push_back(y);
            DP(y, tar);
            colors[x] ^= 1;
            path.push_back(x);
        }
    }
    is_tar[x] = (colors[x] == target);
}

void walk(int t) {
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    fa[t] = 0;
    dep[t] = 0;
    dfs(t);
    while (now != t) {
        now = fa[now];
        colors[now] ^= 1;
        path.push_back(now);
    }
    return;
}

int YN() {
    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    fa[1] = 0;
    dep[1] = 0;
    dfs(1);

    int X = 0, Y = 0;
    for (int i = 1; i <= n; ++i) {
        for (auto j : edges[i]) {
            if ((dep[i] + dep[j]) % 2 == 0) {
                X = i;
                Y = j;
            }
        }
    }
    // cout<<X<<" "<<Y<<endl;
    int tmp = 0, tmpn0 = dep[n] % 2, tmpn1 = dep[n] % 2;
    for (int i = 1; i <= n; ++i) {
        tmp ^= colors[i];
        tmpn1 ^= 1;
    }
    //	cout<<tmp<<" "<<tmpn0<<" "<<tmpn1<<endl;
    // clear edges

    vector<int> V;
    for (int i = 1; i <= n; ++i) {
        V.clear();
        for (auto j : edges[i]) {
            if (fa[j] == i || fa[i] == j) {
                V.push_back(j);
            }
        }
        swap(V, edges[i]);
    }

    if (tmp == tmpn0) {
        return 0;
    }
    if (tmp == tmpn1) {
        return 1;
    }
    if (X == 0 && Y == 0) {
        return -1;
    }

    walk(X);

    now = Y;
    colors[now] ^= 1;
    path.push_back(now);

    //	cout<<now<<" "<<target<<" "<<X<<" "<<Y<<endl;
    //	for(int i=1;i<=n;++i){
    //		cout<<colors[i]<<" ";
    //	}
    //	cout<<endl;

    return 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> colors[i];
    int mr = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    path.clear();
    path.push_back(1);

    now = 1;

    target = YN();

    if (target == -1) {
        cout << "NO" << endl;
        return 0;
    }

    for (int i = 1; i <= n; ++i) {
        vis[i] = 0;
    }
    fa[n] = 0;
    dep[n] = 0;
    dfs(n);
    do {
        DP(now, target);
        if (now != n) {
            // goto fa[now]
            now = fa[now];
            colors[now] ^= 1;
            path.push_back(now);
        } else {
            break;
        }
    } while (1);

    cout << "YES" << endl;
    cout << path.size() - 1 << endl;
    for (auto x : path) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
/*
12 12
0 0 0 0 0 0 0 0 0 1 1 0
1 12
12 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
10 11
11 3


0 0 1 1 1 1
*/