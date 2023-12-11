#include<bits/stdc++.h>
#define lson ( p << 1 )
#define rson ( p << 1 | 1 )
using namespace std;
typedef long long ll;
const int maxn = 2e6 + 10;
const int base = 200001;
int fa[maxn * 40];
int n, m;

int find(int x)
{
    if ( fa[x] != x )
        fa[x] = find(fa[x]);
    return fa[x];
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if ( x == y )
        return;
    fa[x] = y;
    return;
}

inline int get(int x, int k)
{
    return k * base + x;
}
int main()
{
    clock_t start, finish;
    start = clock();
    freopen("C:\\Users\\tob\\Desktop\\0.in","r",stdin);
    // freopen("D:\\Codefield\\CPP\\Contest\\7\\17.out", "w", stdout);
    scanf("%d%d", &n, &m);
    assert(n >= 1 && n <= 100000);
    assert(m >= 1 && m <= 100000);
    // scanf("%s", s + 1);
    for ( int i = 1;i <= 2 * n;i++ ) {
        for ( int k = 0;k <= 20;k++ ) {
            int tt = get(i, k);
            // printf("%d\n", tt);
            assert(tt >= 1 && tt < maxn * 2 * 40);
            fa[tt] = tt;
        }
    }
    for ( int i = 1;i <= n;i++ ) {
        merge(get(i, 0), get(2 * n - i + 1, 0));
    }
    for ( int i = 1;i <= m;i++ ) {
        int l, r;
        scanf("%d%d", &l, &r);
        if(l>r)cout<<"SDFDFS"<<" "<<i<<endl;
        assert(l >= 1 && l <= n);
        assert(r >= 1 && r <= n);
        assert(l <= r);
        int x = 2 * n - r + 1;
        int y = 2 * n - l + 1;
        for ( int j = 20;j >= 0;j-- ) {
            if ( l + (1 << j) - 1 <= r ) {
                int t1 = get(l, j);
                int t2 = get(x, j);
                merge(t1, t2);
                l += (1 << j);
                x += (1 << j);
            }
        }
    }
    for ( int i = 20;i >= 1;i-- ) {
        for ( int j = 1;j <= 2 * n;j++ ) {
            int tt = get(j, i);
            if ( tt == fa[tt] )
                continue;
            int f = find(tt);
            int x = f / base - (f % base == 0);
            int y = f % base ? f % base : base;
            int tt1 = get(j, i - 1);
            int tt2 = get(y, i - 1);
            merge(tt1, tt2);
            tt1 = get(j + (1 << (i - 1)), i - 1);
            tt2 = get(y + (1 << (i - 1)), i - 1);
            merge(tt1, tt2);
        }
    }
    int flag = 0;
    int ans = 0;
    for ( int i = 1;i <= n;i++ ) {
        int t1 = get(i, 0);
        int t2 = get(i + n, 0);
        if ( find(t1) != find(t2) ) {
            flag = 1;
        }
        else ans++;
    }
    if ( flag )
        printf("NO\n");
    else printf("YES\n");
    printf("%d\n", ans);

    finish = clock();
    cout << "the time cost is" <<\
    double(finish - start) / CLOCKS_PER_SEC;

    fclose(stdin);
    return 0;

}