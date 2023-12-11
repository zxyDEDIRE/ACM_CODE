#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i128 __int128
const int mod = 998244353;

i128 ksm(i128 a, i128 b){
    i128 res = 1;
    while(b){
        if(b & 1) res = res * a % XXXXmod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
void solve(){
    ll n, m, k, ans = 0;
    cin >> n >> m >> k;
    k%=n;
    ans=ksm(m%mod,n-k);
    cout << ans << "\n";
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

1
11 2 8
1
1000000000000000000
1000000000000000000
1000000000000000000
*/