#include <bits/stdc++.h>
using namespace std;

#define ll long long

// const int N = 2e5 + 10;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    cout << (b % 2 == c % 2) << " ";
    cout << (a % 2 == c % 2) << " ";
    cout << (a % 2 == b % 2) << "\n";
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