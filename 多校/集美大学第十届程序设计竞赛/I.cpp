#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int x[5];
    for(int i = 0; i < 3; i ++) cin >> x[i];

    int a[5];
    cin >> a[0] >> a[1];

    int b[5];
    cin >> b[0] >> b[1];

    int ans = 0;
    for(int i = a[0]; i <= b[0]; i ++){
        int s = 1, t = 7;
        if(i == a[0]) s = a[1];
        if(i == b[0]) t = b[1] - 1;
        for(int j = s; j <= t; j ++){
            int val = 1;
            for(int k = 0; k < 3; k ++){
                if(x[k] == j) val = 0;
            }
            ans += val;
        }
    }
    cout << ans << "\n";
    return 0;
}
