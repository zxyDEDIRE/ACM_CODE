#include <bits/stdc++.h>
#define readI() read<int>()
#define readL() read<ll>()
#define ls u << 1
#define rs u << 1 | 1
#define lowbit(x) x & -x
#define pb push_back

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;
const int N = 1010;
char s[N][N];
int d[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool v[N][N][4][4];

template<typename T> inline T read()
{
    T x = 0, f = 0;
    char ch = getchar();
    while (!isdigit(ch)) f |= ch=='-', ch = getchar();
    while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
    return f ? -x : x;
}

bool check(int x, int y, int n)
{
    return x <= n && y <= n && x > 0 && y > 0;
}

void solve()
{
    int n = readI();
    int sx, sy, tx, ty;
    memset(v, 0, sizeof v);
    for (int i = 1; i <= n; i ++ )
    {
        cin >> s[i] + 1;
        for (int j = 1; j <= n; j ++ )
        {
            if (s[i][j] == 'A') sx = i, sy = j;
            if (s[i][j] == 'B') tx = i, ty = j;
        }
    }
    deque<array<int, 4>> p;
    for (int i = 0; i < 4; i ++ )
    {
        p.push_back({sx, sy, i, 0});
//         v[sx][sy][i] = 1;
    }
    
    for (int i = 0; i < 4; i ++ )
        for (int j = 0; j < 4; j ++ )
            v[sx][sy][i][j] = 1;
    int ans = 1e9;
    bool flag = false;
    while (p.size())
    {
        auto [x, y, dir, w] = p.front(); p.pop_front();
        if (x == tx && y == ty) {
            flag = true;
            ans = min(ans, w);
        }
        for (int i = 0; i < 4; i ++ )
        {
            int x1 = x + d[i][0], y1 = y + d[i][1];
            if (v[x1][y1][dir][i] || s[x1][y1] == 'x' || !check(x1, y1, n)) continue;
            if (i != dir) p.push_back({x1, y1, i, w+1});
            else p.push_front({x1, y1, i, w});
            v[x1][y1][dir][i] = true;
        }
    }
    if (!flag) puts("-1");
    else cout << ans << endl;
}

int main()
{
    int t = readI();
    while (t -- ) solve();
    return 0;
}