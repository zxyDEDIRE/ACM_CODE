#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll change(vector<int>& num, int k){
    ll sum = 0;
    for(auto x : num){
        sum = sum * k + x;
    }
    return sum;
}

void solve(){
    string t[5];
    int n[5];
    for(int i = 1; i <= 3; i ++){
        cin >> t[i];
        n[i] = t[i].length();
    }

    vector<int> v[5];
    for(int i = 1; i <= 3; i ++){
        for(auto ch : t[i]){
            if(ch >= 'A') v[i].push_back(ch - 'A' + 10);
            else v[i].push_back(ch - '0');
        }
    }

    for(int i = 16; i >= 2; i --){
        ll a = change(v[1], i);
        ll b = change(v[2], i);
        ll c = change(v[3], i);
        if(a + b == c){
            cout << i << "\n";
            return ;
        }
    }
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
