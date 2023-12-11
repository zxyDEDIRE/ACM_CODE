#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int N = 2e5 + 10;
const ll inf = 1e18;

int n, a[N];
ll f[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> a[i];
    sort(a + 1, a + 1 + n);

    ll ans = 0;
    for(int i = 1; i <= n; i += 2){
        ans += a[i + 1] - a[i];
    }
    
    for(int i = 1; i <= n; i ++) f[i] = inf;
    for(int i = 4; i <= n; i ++){
        if(f[i - 4] != inf){
            ll res = 1LL * (a[i] - a[i - 2]) + 1LL * (a[i - 1] - a[i - 3]);
            f[i] = min(f[i], f[i - 4] + res);
        }
        if(f[i - 6] != inf){
            ll res = 1LL * (a[i] - a[i - 2]) + 1LL * (a[i - 1] - a[i - 4]) + 1LL * (a[i - 3] - a[i - 5]);
            f[i] = min(f[i], f[i - 6] + res);
        }
    }
    cout << ans + f[n] << "\n";
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
/*
8
1 2 3 4 5 6 7 8 // 12
*/