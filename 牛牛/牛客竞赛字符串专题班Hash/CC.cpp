#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e6 + 50;

int T = 1;

struct Manacher {
    int n, p[N << 1];
    char s[N << 1];
    void init (char* a) {
        n = 0;
        s[n ++] = '~', s[n ++] = '|';
        for (int i = 0; a[i]; i ++) 
            s[n ++] = a[i], s[n ++] = '|';
        s[n + 1] = 0;
    }
    void get () {
        for (int i = 1, r = 0, mid = 0; i <= n; i ++) {
            if (i <= r) p[i] = min (p[(mid << 1) - i], r - i + 1);
            while (s[i - p[i]] == s[i + p[i]] && i + p[i] <= n) ++ p[i];
            if (p[i] + i > r) r = p[i] + i - 1, mid = i;
        }
    }
};

int n, m;
ll ans[N];
char s[N];
Manacher ma;
struct Query { int l, r, id; } q1[N], q2[N];

auto cmp1 = [](Query x, Query y)->bool {
    return x.r < y.r;
};

auto cmp2 = [](Query x, Query y)->bool {
    return x.l > y.l;
};

struct node {
    int l, r;
    ll add, sum;
}t[N << 2];

#define ls (x << 1)
#define rs (x << 1 | 1)

void build (int l, int r, int x = 1) {
    t[x] = {l, r, 0, 0};
    if (l == r) return ;
    int mid = (l + r) >> 1;
    build (l, mid, ls), build (mid + 1, r, rs);
}

void pushdown (int x) {
    if (t[x].add) {
        t[ls].add += t[x].add;
        t[rs].add += t[x].add;
        t[ls].sum += t[x].add * (t[ls].r - t[ls].l + 1);
        t[rs].sum += t[x].add * (t[rs].r - t[rs].l + 1);
        t[x].add = 0;
    }
}

void pushup (int x) {
    t[x].sum = t[ls].sum + t[rs].sum;
}

void update (int l, int r, int v, int x = 1) {
    // cerr << "here" << endl;
    if (l <= t[x].l && t[x].r <= r) {
        t[x].add += v;
        t[x].sum += v * (ll)(t[x].r - t[x].l + 1);
        return ;
    }
    pushdown (x);
    int mid = (t[x].l + t[x].r) >> 1;
    if (l <= mid) update (l, r, v, ls);
    if (r >  mid) update (l, r, v, rs);
    pushup (x);
}

ll query (int l, int r, int x = 1) {
    if (l <= t[x].l && t[x].r <= r) 
        return t[x].sum;
    pushdown (x);
    int mid = (t[x].l + t[x].r) >> 1;
    ll res = 0;
    if (l <= mid) res += query (l, r, ls);
    if (r >  mid) res += query (l, r, rs);
    return res;
}

// ~|a|b|a|
void solve () {
    scanf ("%d%d%s", &n, &m, s);
    ma.init (s), ma.get ();
    for (int i = 1; i <= m; i ++) {
        int l, r; scanf ("%d%d", &l, &r);
        l = 2 * l - 1, r = 2 * r + 1;
        int mid = (l + r) >> 1;
        q1[i] = {l, mid, i};
        q2[i] = {mid + 1, r, i};
    }
    sort (q1 + 1, q1 + m + 1, cmp1);

    build (1, n);
    for (int i = 1, j = 1; i <= ma.n; i ++) {
        int l = i - ma.p[i] + 1, r = i + ma.p[i] - 1;
        l = (l + 1) >> 1, r = (r - 1) >> 1;
        if (ma.p[i] - 1) update (l, i >> 1, 1);
        for (; j <= m && q1[j].r == i; j ++) {
            l = (q1[j].l + 1) >> 1, r = q1[j].r >> 1;
            // cerr << l << ' ' << r << endl;
            ans[q1[j].id] += query (l, r);
        }
    }
    sort (q2 + 1, q2 + m + 1, cmp2);
    build (1, n);
    for (int i = ma.n, j = 1; i >= 1; i --) {
        int l = i - ma.p[i] + 1, r = i + ma.p[i] - 1;
        l = (l + 1) >> 1, r = (r - 1) >> 1;
        if (ma.p[i] - 1) update ((i + 1) >> 1, r, 1);
        for (; j <= m && q2[j].l == i; j ++) {
            l = (q2[j].l + 1) >> 1, r = q2[j].r >> 1;
            if (l <= r) ans[q2[j].id] += query (l, r);
        }
    }
    for (int i = 1; i <= m; i ++) 
        printf("%lld\n", ans[i]);
}

int main() {
//     freopen ("in.in", "r", stdin);
//     freopen ("out.out", "w", stdout);
    // scanf ("%d", &T);
    while (T --) {
        solve ();
    }
    return 0;
}