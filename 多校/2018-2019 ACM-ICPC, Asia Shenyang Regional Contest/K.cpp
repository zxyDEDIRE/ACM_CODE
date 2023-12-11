#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <stack>
#include <vector>
#include <set>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
#define ld long double
#define lson rt << 1, l, m
#define pi acos(-1)
#define rson rt << 1 | 1, m + 1, r
#define fo(i, l, r) for (long long i = l; i <= r; i++)
#define fd(i, l, r) for (long long i = r; i >= l; i--)
#define mem(x) memset(x, 0, sizeof(x))
#define eps 3e-11
using namespace std;
const ll maxn = 40000050;
const ll mod = 998244353;
ll read()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (!(ch >= '0' && ch <= '9'))
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    };
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0');
        ch = getchar();
    };
    return x * f;
}
ll n, m, k;
int main()
{
    int T;
    T = read();
    int tt = 0;
    while (T--)
    {
        tt++;
        n = read();
        m = read();
        k = read();
        ll ans = (k - 1) % (n - m + 1);
        if (k == 1)
        {
            ans = m - 1;
        }
        else
        {
            fo(i, n - m + 2, n)
            {
                ans = (ans + k) % i;
                ll js = i - ans - 1;
                js /= k;
                js--;
                if (n - i - 1 < js)
                    js = n - i - 1;
                if (js > 0)
                {
                    i += js;
                    ans = ans + k * js;
                }
            }
        }
        printf("Case #%d: %I64d\n", tt, ans + 1);
    }
    return 0;
}