#include "bits/stdc++.h"

using namespace std;
using ull = unsigned long long;
using ll = long long;
constexpr int B = 114514;
constexpr ull P = 1000000000039;

struct StringHash {
    vector<ull> h;
    vector<ull> bas;
    StringHash() : h(1),bas(1,1) {}
    void push_back(char ch) {
        h.push_back((h.back() * B + ch) % P);
        bas.push_back(bas.back() * B %P);
    }
    ull get(int l, int r) { // [l, r)
        return (h[r] + __int128(h[l]) * (P - bas[r - l])) % P;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
//     init(4E5);    
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<pair<int, ll>> q;
    for (int i = 0; i < m; i++) {
        int o;
        cin >> o;
        if (o == 1) {
            char x;
            cin >> x;
            s.push_back(x);
        } else {
            ll k;
            cin >> k;
            q.push_back({(int) s.size(), k});
        }
    }
    const int N = s.size();

    StringHash hs, rhs;
    for (int i = 0; i < N; i++) {
        hs.push_back(s[i]);
    }
    for (int i = N - 1; i >= 0; i--) {
        rhs.push_back(s[i]);
    }

    for (auto &[n, k] : q) {
        k = k % (2 * n);
        if (k > n) {
            cout << (
                hs.get(0, 2 * n - k) == hs.get(k - n, n) && 
                hs.get(0, k - n) == rhs.get(N - k + n, N) && 
                hs.get(2 * n - k, n) == rhs.get(N - n, N - 2 * n + k) ? "Yes" : "No" 
            ) << '\n';
        } else if (k == n) {
            cout << "Yes\n";
        } else if (k > 0) {
            cout << (
                hs.get(0, k) == hs.get(n - k, n) && 
                hs.get(0, n - k) == rhs.get(N - n + k, N) &&
                hs.get(k, n) == rhs.get(N - n, N - k) ? "Yes" : "No"
            ) << '\n';
        } else {
            cout << (hs.get(0, n) == rhs.get(N - n, N) ? "Yes" : "No") << '\n';
        }
    }

    return 0;
}